@echo off

if /i %1 == "" exit
::echo %1
::echo %2
set token=%1
set /a duration=%2
::echo %token%
::echo %duration%
setlocal enableextensions
setlocal enabledelayedexpansion

PATH=%PATH%;"%PROGRAMFILES%\NVIDIA Corporation\NVSMI\"

:for /f %%i in ('nvidia-smi --query-gpu=count --format=csv,noheader') do set "GPUCount=%%i"
nvidia-smi --query-gpu=count --format=csv,noheader > GPU.txt
set /p GPUCount=<GPU.txt
::pause
del GPU.txt
::echo %GPUCount%
set /a GPUCount = %GPUCount - 1
::echo %GPUCount%
::pause

for /f "skip=1 delims=" %%A in ('wmic computersystem get name') do for /f "delims=" %%B in ("%%A") do set "RigsNo=%%~nxB"
::echo %RigsNo%

:: Check WMIC is available
WMIC.EXE Alias /? >NUL 2>&1 || GOTO s_error

:: Use WMIC to retrieve date and time
FOR /F "skip=1 tokens=1-6" %%G IN ('WMIC Path Win32_LocalTime Get Day^,Hour^,Minute^,Month^,Second^,Year /Format:table') DO (
   IF "%%~L"=="" goto s_done
      Set _yyyy=%%L
      Set _mm=00%%J
      Set _dd=00%%G
      Set _hour=00%%H
      SET _minute=00%%I
)
:s_done

:: Pad digits with leading zeros
      Set _mm=%_mm:~-2%
      Set _dd=%_dd:~-2%
      Set _hour=%_hour:~-2%
      Set _minute=%_minute:~-2%

:: Display the date/time in ISO 8601 format:
Set datetime=%_dd%/%_mm%/%_yyyy% %_hour%:%_minute%

curl -X POST -H "Authorization: Bearer %token%" -F "message=#===== %RigsNo% =====#" https://notify-api.line.me/api/notify
curl -X POST -H "Authorization: Bearer %token%" -F "message=%datetime%" https://notify-api.line.me/api/notify

::curl -X POST -H "Authorization: Bearer 5H3tWIacxbdj1baIbjzsRsLG2Ht4XVkzqFv2zqQv2dc" -F "message=#=================#" https://notify-api.line.me/api/notify
::curl -X POST -H "Authorization: Bearer 5H3tWIacxbdj1baIbjzsRsLG2Ht4XVkzqFv2zqQv2dc" -F "message=%datetime% %RigsNo% GPU Status" https://notify-api.line.me/api/notify

:loop

for /l %%a in (0, 1, %GPUCount%) do (
::nvidia-smi -i %%a --query-gpu=index,name,temperature.gpu,fan.speed,clocks.gr,clocks.mem,pstate,power.draw,power.limit --format=csv,noheader > tmp.txt 
nvidia-smi -i %%a --query-gpu=index,name,temperature.gpu,fan.speed,clocks.gr,clocks.mem,power.draw --format=csv,noheader > tmp.txt 
set /p val=<tmp.txt
del tmp.txt
::echo !val!
curl -X POST -H "Authorization: Bearer %token%" -F "message=!val!" https://notify-api.line.me/api/notify 
)
timeout /t %duration%
goto loop
::timeout /t 3600 /nobreak >nul
