# TaintART deploy
First you have to have an AOSP build whose version corresponds with the TaintART version.

Reccommended host system ubuntu-16.04, wsl is not reccommended. You have to have jdk 1.8 installed and activated.

## download repo
`mkdir ~/bin`
`PATH=~/bin:$PATH`
`curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo`
`chmod a+x ~/bin/repo`

## download image
`repo init -u https://aosp.tuna.tsinghua.edu.cn/platform/manifest -b android-7.1.2_r6`
`repo sync`
Then have a coffee break.

## build AOSP
`source build/envsetup.sh`
`lunch 6 #for x86_64`
`make -j24`
Then have a sleep.

## build TaintART image
copy the TaintART release to art folder in the root directory
copy all the *.sh from art/tools to the root directory
`./buildbot*.sh`
Then have some exercises.
`make snod -j24`
`emulator`
You are now to see the system with TaintART installed but without plugin notification apps.