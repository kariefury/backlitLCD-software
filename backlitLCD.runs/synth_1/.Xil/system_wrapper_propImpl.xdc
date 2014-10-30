set_property SRC_FILE_INFO {cfile:/usr9/research/chsegal/Documents/ECE153A/Artix7/lab3/backlitLCD/backlitLCD.srcs/sources_1/bd/system/ip/system_clk_wiz_1_0/system_clk_wiz_1_0.xdc rfile:../../../backlitLCD.srcs/sources_1/bd/system/ip/system_clk_wiz_1_0/system_clk_wiz_1_0.xdc id:1 order:EARLY scoped_inst:system_i/clk_wiz_1/inst} [current_design]
set_property src_info {type:SCOPED_XDC file:1 line:56 export:INPUT save:INPUT read:READ} [current_design]
set_input_jitter [get_clocks -of_objects [get_ports clk_in1]] 0.1
