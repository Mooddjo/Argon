del Argon.sln
rmdir /Q /S .vs

rmdir /Q /S ..\Sources\Argon\.vs
del ..\Sources\Argon\Argon.vcxproj
del ..\Sources\Argon\Argon.vcxproj.*

rmdir /Q /S ..\Sources\Playground\.vs
del ..\Sources\Playground\Playground.vcxproj
del ..\Sources\Playground\Playground.vcxproj.*

rmdir /Q /S ..\.vs
pause