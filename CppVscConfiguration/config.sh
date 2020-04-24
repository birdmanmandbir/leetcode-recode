#!/bin/bash
# 注意在有.vscode的目录运行
# task.json
cat > .vscode/tasks.json << EOF
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "type": "shell",
            "command": "g++",
            "args": [
                "-std=c++17",
                "-Wall",
                "-Wextra",
                "-g",
                "-ggdb",
                "mycpp.cpp",
                "-o",
                "demoapp.out"
            ],
            "group": "build",
            "presentation": {
                "reveal": "always",
            },
            "problemMatcher": "\$gcc"
        }
    ]
}
EOF

# launch.json
cat > .vscode/launch.json << EOF
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "\${workspaceFolder}/demoapp.out",
            "args": [],
            "stopAtEntry": false,
            "cwd": "\${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "build"
        }
    ]
}
EOF


# cpp property.json
if [ `getconf LONG_BIT` -eq "64" ]; then
cat > .vscode/c_cpp_properties.json << EOF
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "/usr/include/c++/8",
                "/usr/include/x86_64-linux-gnu/c++/8",
                "/usr/include/c++/8/backward",
                "/usr/lib/gcc/x86_64-linux-gnu/8/include",
                "/usr/local/include",
                "/usr/lib/gcc/x86_64-linux-gnu/8/include-fixed",
                "/usr/include/x86_64-linux-gnu",
                "/usr/include",
                "${workspaceRoot}"
            ],
            "defines": [],
            "intelliSenseMode": "clang-x64",
            "browse": {
                "path": [
                    "/usr/include/c++/8",
                    "/usr/include/x86_64-linux-gnu/c++/8",
                    "/usr/include/c++/8/backward",
                    "/usr/lib/gcc/x86_64-linux-gnu/8/include",
                    "/usr/local/include",
                    "/usr/lib/gcc/x86_64-linux-gnu/8/include-fixed",
                    "/usr/include/x86_64-linux-gnu",
                    "/usr/include",
                    "${workspaceRoot}"
                ],
                "limitSymbolsToIncludedHeaders": true,
                "databaseFilename": ""
            }
        }
    ],
    "version": 3
}
EOF
else
cat > .vscode/c_cpp_properties.json << EOF
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "/usr/include/c++/8",
                "/usr/include/i386-linux-gnu/c++/8",
                "/usr/include/c++/8/backward",
                "/usr/lib/gcc/i686-linux-gnu/8/include",
                "/usr/local/include",
                "/usr/lib/gcc/i686-linux-gnu/8/include-fixed",
                "/usr/include/i386-linux-gnu",
                "/usr/include",
                "${workspaceRoot}"
            ],
            "defines": [],
            "intelliSenseMode": "clang-x64",
            "browse": {
                "path": [
                    "/usr/include/c++/8",
                    "/usr/include/i386-linux-gnu/c++/8",
                    "/usr/include/c++/8/backward",
                    "/usr/lib/gcc/i686-linux-gnu/8/include",
                    "/usr/local/include",
                    "/usr/lib/gcc/i686-linux-gnu/8/include-fixed",
                    "/usr/include/i386-linux-gnu",
                    "/usr/include",
                    "${workspaceRoot}"
                ],
                "limitSymbolsToIncludedHeaders": true,
                "databaseFilename": ""
            }
        }
    ],
    "version": 3
}
EOF
fi


