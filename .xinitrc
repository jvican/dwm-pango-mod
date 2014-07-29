# Setting up browser environment variable to open URL's with turses
export BROWSER=firefox

# Trick Window Manager for JDK Bugs
wmname LG3D

# Refreshing .Xresources file and font cache
xrdb -merge /home/turing/.Xresources
xset +fp /usr/share/fonts/local
xset fp rehash
xset -b

# Launching rxvt-unicode daemon
urxvtd -q -o -f

feh --bg-scale $HOME/.wallpapers/Galaxy5.jpg

while true; do 
	$HOME/Scripts/dwm-status.sh
	sleep 2
done &

# Launching Dynamic Window Manager, dwm rocks!
exec dwm
