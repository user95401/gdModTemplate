set "$Title=Update binary in geode package:"
set "$Message=Done!"

::go to root dir of project
cd "../../../"
::copy dll
if not exist "%4/%2.dll" set "$Message=Can´t found %4/%2.dll to copy dll!"
if exist "%4/%2.dll" powershell Copy-Item "%4/%2.dll" -Destination "geode"
::rename dll
if not exist "geode/%2.dll" set "$Message=Can´t found geode/%2.dll to rename dll!"
if exist "geode/%2.dll" powershell Rename-Item -Path "geode/%2.dll" -NewName "%1.%2.dll"
::go to geode dir of project
cd "./geode"

::rename geode to zip
if not exist "Release/%1.%2.geode" set "$Message=Can´t found geode/Release/%1.%2.geode to rename geode to zip!"
if exist "Release/%1.%2.geode" powershell Rename-Item -Path "Release/%1.%2.geode" -NewName "%1.%2.zip"
::Update dll in it
if not exist "Release/%1.%2.zip" set "$Message=Can´t found geode/Release/%1.%2.zip to update dll in it!"
if exist "Release/%1.%2.zip" powershell Compress-Archive -Path "%1.%2.dll" -CompressionLevel "Fastest" -DestinationPath "Release/%1.%2.zip" -Update
::rename back to .geode
if not exist "Release/%1.%2.zip" set "$Message=Can´t found geode/Release/%1.%2.zip to rename back to .geode!"
if exist "Release/%1.%2.zip" powershell Rename-Item -Path "Release/%1.%2.zip" -NewName "%1.%2.geode"
::copy updated geode to game
if not exist "Release/%1.%2.geode" set "$Message=Can´t found geode/Release/%1.%2.geode to copy updated geode to game!"
if exist "Release/%1.%2.geode" powershell Copy-Item "Release/%1.%2.geode" -Destination "%5"

::remove old dll in Release
if not exist "Release/%1.%2.dll" set "$Message=Can´t found geode/Release/%1.%2.dll to remove old dll in Release!"
if exist "Release/%1.%2.dll" powershell Remove-Item "Release/%1.%2.dll"
::move dll to Release
if not exist "%1.%2.dll" set "$Message=Can´t found geode/%1.%2.dll to move dll to Release!"
if exist "%1.%2.dll" move "%1.%2.dll" "Release"

::BEEEp if smth wrong
if not "%$Message%" == "Done!" rundll32 user32.dll,MessageBeep
::add warn emoji
if not "%$Message%" == "Done!" set "$Title=⚠️ Failed to %$Title%"

::push notify
powershell -Command "& {Add-Type -AssemblyName System.Windows.Forms; Add-Type -AssemblyName System.Drawing; $notify = New-Object System.Windows.Forms.NotifyIcon; $notify.Icon = [System.Drawing.SystemIcons]::Information; $notify.Visible = $true; $notify.ShowBalloonTip(0, '%$Title%', '%$Message%', [System.Windows.Forms.ToolTipIcon]::None)}"
