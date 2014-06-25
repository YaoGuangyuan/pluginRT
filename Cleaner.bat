rem ======= 删除Debug和Release目录 ========= 

rd  /s /q "%~dp0./ipch"
rd  /s /q "%~dp0./Debug"
rd  /s /q "%~dp0./Release"
rd  /s /q "%~dp0./PluginRuntime/Debug"
rd  /s /q "%~dp0./PluginRuntime/Release"
rd  /s /q "%~dp0./PluginExample/Debug"
rd  /s /q "%~dp0./PluginExample/Release"
rd  /s /q "%~dp0./PluginRuntimeDemo/Debug"
rd  /s /q "%~dp0./PluginRuntimeDemo/Release"


rem ======= 删除非隐藏的特殊格式的文件 ========= 

del /f /s /q  *.cdf
del /f /s /q  *.cache
del /f /s /q  *.obj
del /f /s /q  *.ilk
del /f /s /q  *.resources
del /f /s /q  *.tlb
del /f /s /q  *.tli
del /f /s /q  *.tlh
del /f /s /q  *.tmp
del /f /s /q  *.rsp
del /f /s /q  *.pgc
del /f /s /q  *.pgd
del /f /s /q  *.meta
del /f /s /q  *.tlog
del /f /s /q  *.manifest
del /f /s /q  *.pch
del /f /s /q  *.exp
del /f /s /q  *.idb
del /f /s /q  *.rep
del /f /s /q  *.xdc
del /f /s /q  *.pdb
del /f /s /q  *_manifest
del /f /s /q  *.bsc
del /f /s /q  *.sbr
del /f /s /q  *.ncb
del /f /s /q  *.opensdf
del /f /s /q  *.sdf
del /f /s /q  *.aps
del /f /s /q  *.sln.txt

rem ======= 删除隐藏的特殊格式的文件 ========= 

del /f /s /q /a:h-s  *.suo