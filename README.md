# Stm32g070

## Build
* Терминал > Запуск задачи > Make Build
* Терминал > Замуск задачи > Make Clean

## SVD файл взят из
* C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\SVD
* файл положили в ./JLink
* указали путь в ./.vscode/launch.json
* также в ./.vscode/launch.json указать правильные elf из build

## Трабшутинг после регенерации
В секции C defines у `Makefile` удалить `DCMSIS_device_header`
было
```
# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32G070xx \
-DCMSIS_device_header=<stm32g0xx.h>
```
стало
```
# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32G070xx
```
(может можно этот файл таки куда-то положить чтобы каждый раз не грохать после генерации кода CubeMX)
