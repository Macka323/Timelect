This project works with the DisplayApp;
Api

## /connect/####
the /#### are 4 random numbers that are sumed up to vierify that the device is present

## /setPixel/x##y##r###g###b###
### Paramatars

`x`,`y` - coordinates for the led

`r`,`g`,`b`, - the red, green, blue value for the led

## /setPixels
in the body request the must contain a list of `x##y##r###g###b###` commands separated by `\n`

## /getPixel/x##y##
return string `r###g###b###`

## /getPixels
returns a list of `x##y##r###g###b###` commands separated by `\n`