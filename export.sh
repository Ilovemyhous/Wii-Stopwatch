bash # Fish is bugged for some reason.
# At Terminal startup.
echo "export DEVKITPPC=/opt/devkitpro/devkitPPC" >> ~/.bashrc
echo "export DEVKITARM=/opt/devkitpro/devkitARM" >> ~/.bashrc
echo "export DEVKITPRO=/opt/devkitpro" >> ~/.bashrc
# On the fly.
export DEVKITPPC=/opt/devkitpro/devkitPPC
export DEVKITARM=/opt/devkitpro/devkitARM
export DEVKITPRO=/opt/devkitpro
source ~/.bashrc