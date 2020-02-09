# albertgg's Vanilla Whitefox Layout

[WhiteFox][whitefox] vanilla layout keymap.

## features

- Base layers
  - QWERTY
  - FUNC
  - MEDIA (macOS)

## Building and Flashing

1. Build the firmware
```bash
$ make whitefox:albertogg
```
1. Put your board in DFU mode with either the button on the bottom, or with a
   software key in your current firmware
1. Use the [QMK Toolbox][qmk-toolbox] to flash the firmware

[whitefox]: https://input.club/whitefox/
[qmk-toolbox]: https://github.com/qmk/qmk_toolbox
