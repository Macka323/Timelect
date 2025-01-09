# Display mode

All of the commands are sent as byte[]

At at end of every command you must send 255 as byte to mark the end of the command

# sp

sets the pixel at the specified x,y location with the rgb values

Example command `sp12345 `

> sp is the command name
>
> 1 is the the pixels x coordinate type of byte
>
> 2 is the the pixels y coordinate type of byte
>
> 3 is the the pixels r value type of byte
>
> 4 is the the pixels g value type of byte
>
> 5 is the the pixels b value type of byte

