# Захват экрана для Resolume Arena

FFGL-источник для захвата окна или всего дисплея в Resolume Arena 7. Поддерживает macOS (Intel и Apple Silicon) и Windows. Отдельная сборка для Arena 6 доступна на macOS.

## Установка на macOS

1. Собери `ScreenCapture.bundle` или скачай архив из Releases.
2. Помести bundle в `~/Documents/Resolume Arena/Extra Effects/`.
3. Дай Arena разрешение на запись экрана в настройках конфиденциальности macOS и перезапусти её.
4. В Arena выбери источник **Захват экрана** и выбери окно или дисплей.

## Сборка macOS

```sh
cmake -S . -B build -DPLUGIN_VERSION=1.0.0 -DUPDATE_MANIFEST_URL=
cmake --build build --target ScreenCapture --parallel 4
```

Для Windows открой `build.bat` в Developer Command Prompt for Visual Studio 2022. GitHub Actions собирает релизные архивы для обеих платформ.
