@echo off

if /i %1 == "" exit
::echo %1
set token=%1

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

curl -X POST -H "Authorization: Bearer %token%" -F "message=%RigsNo% reboot time: %datetime%" https://notify-api.line.me/api/notify