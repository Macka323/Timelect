This project works with the DisplayApp;

# Api

## /connect/####
the /#### are 4 random numbers that are sumed up to vierify that the device is present

## sp##### (setPixel)
### Paramatars

`x`,`y` - coordinates for the led

`r`,`g`,`b`, - the red, green, blue value for the led

## /setPixels
in the body request the must contain a list of `x##y##r###g###b###` commands separated by `\n`

## /getPixel/x##y##
return string `r###g###b###`

## /getPixels
returns a list of `x##y##r###g###b###` commands separated by `\n`

# Connection

## The device is connected to your network
## First time setup or wrong network credentionals
- If the Device is not conected to your network, then it will create its own WIFI network called `ESP Display`.
    - Then you will need to connect to that network, and open the `Display app configuration page` in there you can go to `WIFI config section` and configure it with your WIFI name and password, then click `configure`.
    - This action will take from 1-2 minutes.
    - If you know the device ip you can connect to it
    - If you dont it will attempt to automaticly find the device if the display is connected to the network. Also it may not work if you have vpn turned on or some other network middllware that is stopping the requests like virtual adapters from emulators/virtualization.
    - Connect to your network, and click the `connect` button.