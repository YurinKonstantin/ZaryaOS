@echo off
echo *
echo * Deleting all OBJs below %cd%
echo *
echo *
for /f "tokens=*" %%i IN (D:\srv03rtm\list.txt) DO echo :  %%i
echo * Deleting all build.xxx files %cd%
echo *

