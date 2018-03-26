#!/bin/sh
docker build -t hitcon_training - <<DOCKERFILE_EOF || exit 1
from ubuntu
run apt-get update
run apt-get install -y git sudo bash make nano
run dpkg --add-architecture i386
run apt-get update
run git clone https://github.com/scwuaptx/HITCON-Training /tmp/hitcon
workdir /tmp/hitcon
run bash env_setup.sh
run git clone https://github.com/radare/radare2 /tmp/radare2
workdir /tmp/radare2
run sys/install.sh
workdir /tmp/hitcon
cmd bash -i
DOCKERFILE_EOF

docker run -it --rm --cap-add=SYS_PTRACE --security-opt seccomp=unconfined hitcon_training