# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\TUTORIALS\PSOC_LAB1\led_blink_pwm.cydsn\led_blink_pwm.cyprj
# Date: Mon, 22 Mar 2021 18:41:52 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 94489 188977} [list [get_pins {ClockBlock/udb_div_0}]]


# Component constraints for D:\TUTORIALS\PSOC_LAB1\led_blink_pwm.cydsn\TopDesign\TopDesign.cysch
# Project: D:\TUTORIALS\PSOC_LAB1\led_blink_pwm.cydsn\led_blink_pwm.cyprj
# Date: Mon, 22 Mar 2021 18:41:49 GMT
