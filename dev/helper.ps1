function LyReleasePackage () {
    .\lmbr_waf.bat build_win_x64_vs2017_profile -p all
    .\lmbr_waf.bat build_win_x64_vs2017_release -p game_and_engine

    if (Test-Path -Path .\myproject_pc_paks\) {
        Remove-Item .\myproject_pc_paks\ -Recurse -Force
    }

    .\BuildMyProject_Paks_PC.bat
    Copy-Item .\Bin64vc141.Release\ `
        -Destination .\myproject_pc_paks\ -Recurse -Force -Verbose
    .\BuildShaderPak_DX11_MyProject.bat
    Copy-Item .\Build\pc\MyProject\*.pak `
        -Destination .\myproject_pc_paks\myproject\ `
        -Force -Verbose
}

function LyProjectConfigurator()
{
    .\Bin64vc141\ProjectConfigurator.exe
}

function LyEditor()
{
    .\Bin64vc141\Editor.exe
}

function LyBuildAll()
{
    .\lmbr_waf.bat build_win_x64_vs2017_profile -p all
}

function LyBuildAllDedicated()
{
    .\lmbr_waf.bat build_win_x64_vs2017_profile_dedicated -p all
}

function LyBuild()
{
    .\lmbr_waf.bat build_win_x64_vs2017_profile -p game
}
function LyBuildDedicated()
{
    .\lmbr_waf.bat build_win_x64_vs2017_profile_dedicated -p game
}
function LyConfigure()
{
    .\lmbr_waf.bat configure -p game
}

function LyBuildTestAll() {
    .\lmbr_waf.bat build_win_x64_vs2017_profile_test -p all
}

function LyBuildTestDebugAll() {
    .\lmbr_waf.bat build_win_x64_vs2017_debug_test -p all
}
function Start-MyProject() {
    .\Bin64vc141\MyProjectLauncher.exe +windowxy 5 5
    .\Bin64vc141\MyProjectLauncher.exe +windowxy 550 250
}