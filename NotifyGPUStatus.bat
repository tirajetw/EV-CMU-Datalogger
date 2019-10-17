@echo off
:: How to use การใช้งาน
:: GPUStatus.bat [Line_Token] [Time_second]
:: Example: GPUStatus.bat xxxxxx 60 // แจ้งเตือนทุก 1 นาที
:: Example: GPUStatus.bat xxxxxx 3600 // แจ้งเตือนทุก 1 ชั่วโมง
:: Example: GPUStatus.bat xxxxxx 86400 // แจ้งเตือนทุก 24 ชั่วโมง
:: Line: index, name, Temperature, fan speed, core clock, mem clock, power

cd Batch
GPUStatus.bat xxxxxxxxxxxxx 3600
