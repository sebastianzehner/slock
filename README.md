# My build of slock - a simple X display locker

This is my custom build of [slock](https://tools.suckless.org/slock/), a simple X display locker originally from the official [suckless](https://suckless.org/) website, customized to suit my personal needs while still keeping it the simplest X screen locker with all necessary functionality.

## Applied Patches

I have applied the following patches to enhance functionality and appearance:

- [`capscolor`](https://tools.suckless.org/slock/patches/capscolor/)
- [`colormessage`](https://tools.suckless.org/slock/patches/colormessage/)
- [`xresources`](https://tools.suckless.org/slock/patches/xresources/)

## Patch Functionality

These patches add useful visual and customization features to **slock**. The `capscolor` patch changes the screen color when `Caps Lock` is active, providing clear feedback.

The `colormessage` adds a customizable status message (e.g., "This computer is locked") on the lock screen, and `xresources` allows configuring colors and messages dynamically through `.Xresources`, making it easier to theme **slock** without recompiling.

## Additional Customizations

A short **slock_now.sh** script is used to immediately lock the screen via the **dmenu** power menu when **Lock** is selected:

```bash
#!/bin/bash

# start slock with timestamped message
slock -m "$(printf "%s\n Locked at %s" "$(figlet 'Lock Screen')" "$(date "+%a %d, %H:%M:%S")")"
```

> Note: The `figlet` command is optional and adds a fun ASCII banner to the lock message. Make sure `figlet` is installed if you want that effect.

In `~/.xinitrc`, `xautolock` is configured to automatically lock the screen after 10 minutes of inactivity:

```bash
# autolock after 10 minutes of inactivity
xautolock -time 10 -locker ~/code/slock_now.sh &
```

Colors are based on the [Catppuccin Mocha](https://github.com/catppuccin/catppuccin) colorscheme with the font set to `10x20`.

## Key Bindings

No special key bindings are required - just type your password and press `Enter` to unlock the screen.

Although the `capscolor` patch is applied, I’ve remapped the `Caps Lock` key to `Ctrl + S` using VIA app, so it now serves as a Leader key in **NeoVim** and **Tmux**. The patch remains - just in case `Caps Lock` ever makes a surprise comeback.

## Installation

```bash
git clone https://github.com/sebastianzehner/slock
cd slock
doas make install
```

If you're using `sudo` instead of `doas`, replace the last line accordingly.

## Disclaimer

I'm not a professional developer - just a hobbyist sharing my personal setup.  
This build is provided as-is, with no guarantees that it will work for you.  
If something breaks, you're on your own - but feel free to explore, adapt, and improve!
