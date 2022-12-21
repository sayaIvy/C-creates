# background
# lightblue 0x7B
# white 0xE7
# gray 0xF6
# black 0xE8


for ((i = 0; i < 16; i++)); do
    for ((j = 0; j < 16; j++)); do
        hex=$(($i*16 + $j))
        printf '\e[38;5;%dm0x%02X\e[m ' $hex $hex
    done
    echo "";
done

for ((i = 0; i < 16; i++)); do
    for ((j = 0; j < 16; j++)); do
        hex=$(($i*16 + $j))
        printf '\e[48;5;%dm0x%02X\e[m ' $hex $hex
        printf '%dm0x%02' $hex $hex
    done
    echo "";
done

for ((a = 0; a < 20; a++)); do
    printf '\e[48;5;%dm0x%02X0xF6\e[m ' $hex $hex
done