#!/usr/bin/sh
#   
#   BUILD SCRIPT FILE 
#   Script to build a version of the game /
#

make build
echo
echo
echo

f_date=$(date +'%m-%d-%Y')
f_name="road66_build_${f_date}"
file_name="road66"

echo "== creating folder"
mkdir ${f_name}

echo "== importing executable"
mv make_out ./${f_name}/${file_name}

echo "== import events"
cp -avr ./event/ ./${f_name}/

echo "== import window script"
cp -avr ./scripts/window_launcher.bat ./${f_name}/

cd ${f_name}
mkdir config

echo "== importing config"
cp -avr ../config/config.cfg ./config/