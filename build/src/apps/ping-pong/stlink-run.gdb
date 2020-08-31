file ping-pong
target extended localhost:4242
monitor reset halt
shell sleep 1
load
thbreak main
