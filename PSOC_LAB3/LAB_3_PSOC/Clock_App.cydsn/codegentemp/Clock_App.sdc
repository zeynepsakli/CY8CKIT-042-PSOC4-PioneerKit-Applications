# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\TUTORIALS\PSOC_LAB3\LAB_3_PSOC\Clock_App.cydsn\Clock_App.cyprj
# Date: Fri, 02 Apr 2021 19:14:34 GMT
#set_units -time ns
create_clock -name {Clock_1(FFB)} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {CyRouted1} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 3001 6001} [list]


# Component constraints for D:\TUTORIALS\PSOC_LAB3\LAB_3_PSOC\Clock_App.cydsn\TopDesign\TopDesign.cysch
# Project: D:\TUTORIALS\PSOC_LAB3\LAB_3_PSOC\Clock_App.cydsn\Clock_App.cyprj
# Date: Fri, 02 Apr 2021 19:14:31 GMT