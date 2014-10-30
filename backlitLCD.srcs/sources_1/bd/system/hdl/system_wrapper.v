//Copyright 1986-2014 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2014.1 (lin64) Build 881834 Fri Apr  4 14:00:25 MDT 2014
//Date        : Mon Sep 29 15:48:39 2014
//Host        : nova.ece.ucsb.edu running 64-bit CentOS release 6.5 (Final)
//Command     : generate_target system_wrapper.bd
//Design      : system_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module system_wrapper
   (btnCpuReset,
    clock_rtl,
    lcd_tri_io);
  input btnCpuReset;
  input clock_rtl;
  inout [10:0]lcd_tri_io;

  wire btnCpuReset;
  wire clock_rtl;
  wire [0:0]lcd_tri_i_0;
  wire [1:1]lcd_tri_i_1;
  wire [10:10]lcd_tri_i_10;
  wire [2:2]lcd_tri_i_2;
  wire [3:3]lcd_tri_i_3;
  wire [4:4]lcd_tri_i_4;
  wire [5:5]lcd_tri_i_5;
  wire [6:6]lcd_tri_i_6;
  wire [7:7]lcd_tri_i_7;
  wire [8:8]lcd_tri_i_8;
  wire [9:9]lcd_tri_i_9;
  wire [0:0]lcd_tri_io_0;
  wire [1:1]lcd_tri_io_1;
  wire [10:10]lcd_tri_io_10;
  wire [2:2]lcd_tri_io_2;
  wire [3:3]lcd_tri_io_3;
  wire [4:4]lcd_tri_io_4;
  wire [5:5]lcd_tri_io_5;
  wire [6:6]lcd_tri_io_6;
  wire [7:7]lcd_tri_io_7;
  wire [8:8]lcd_tri_io_8;
  wire [9:9]lcd_tri_io_9;
  wire [0:0]lcd_tri_o_0;
  wire [1:1]lcd_tri_o_1;
  wire [10:10]lcd_tri_o_10;
  wire [2:2]lcd_tri_o_2;
  wire [3:3]lcd_tri_o_3;
  wire [4:4]lcd_tri_o_4;
  wire [5:5]lcd_tri_o_5;
  wire [6:6]lcd_tri_o_6;
  wire [7:7]lcd_tri_o_7;
  wire [8:8]lcd_tri_o_8;
  wire [9:9]lcd_tri_o_9;
  wire [0:0]lcd_tri_t_0;
  wire [1:1]lcd_tri_t_1;
  wire [10:10]lcd_tri_t_10;
  wire [2:2]lcd_tri_t_2;
  wire [3:3]lcd_tri_t_3;
  wire [4:4]lcd_tri_t_4;
  wire [5:5]lcd_tri_t_5;
  wire [6:6]lcd_tri_t_6;
  wire [7:7]lcd_tri_t_7;
  wire [8:8]lcd_tri_t_8;
  wire [9:9]lcd_tri_t_9;

IOBUF lcd_tri_iobuf_0
       (.I(lcd_tri_o_0),
        .IO(lcd_tri_io[0]),
        .O(lcd_tri_i_0),
        .T(lcd_tri_t_0));
IOBUF lcd_tri_iobuf_1
       (.I(lcd_tri_o_1),
        .IO(lcd_tri_io[1]),
        .O(lcd_tri_i_1),
        .T(lcd_tri_t_1));
IOBUF lcd_tri_iobuf_10
       (.I(lcd_tri_o_10),
        .IO(lcd_tri_io[10]),
        .O(lcd_tri_i_10),
        .T(lcd_tri_t_10));
IOBUF lcd_tri_iobuf_2
       (.I(lcd_tri_o_2),
        .IO(lcd_tri_io[2]),
        .O(lcd_tri_i_2),
        .T(lcd_tri_t_2));
IOBUF lcd_tri_iobuf_3
       (.I(lcd_tri_o_3),
        .IO(lcd_tri_io[3]),
        .O(lcd_tri_i_3),
        .T(lcd_tri_t_3));
IOBUF lcd_tri_iobuf_4
       (.I(lcd_tri_o_4),
        .IO(lcd_tri_io[4]),
        .O(lcd_tri_i_4),
        .T(lcd_tri_t_4));
IOBUF lcd_tri_iobuf_5
       (.I(lcd_tri_o_5),
        .IO(lcd_tri_io[5]),
        .O(lcd_tri_i_5),
        .T(lcd_tri_t_5));
IOBUF lcd_tri_iobuf_6
       (.I(lcd_tri_o_6),
        .IO(lcd_tri_io[6]),
        .O(lcd_tri_i_6),
        .T(lcd_tri_t_6));
IOBUF lcd_tri_iobuf_7
       (.I(lcd_tri_o_7),
        .IO(lcd_tri_io[7]),
        .O(lcd_tri_i_7),
        .T(lcd_tri_t_7));
IOBUF lcd_tri_iobuf_8
       (.I(lcd_tri_o_8),
        .IO(lcd_tri_io[8]),
        .O(lcd_tri_i_8),
        .T(lcd_tri_t_8));
IOBUF lcd_tri_iobuf_9
       (.I(lcd_tri_o_9),
        .IO(lcd_tri_io[9]),
        .O(lcd_tri_i_9),
        .T(lcd_tri_t_9));
system system_i
       (.btnCpuReset(btnCpuReset),
        .clock_rtl(clock_rtl),
        .lcd_tri_i({lcd_tri_i_10,lcd_tri_i_9,lcd_tri_i_8,lcd_tri_i_7,lcd_tri_i_6,lcd_tri_i_5,lcd_tri_i_4,lcd_tri_i_3,lcd_tri_i_2,lcd_tri_i_1,lcd_tri_i_0}),
        .lcd_tri_o({lcd_tri_o_10,lcd_tri_o_9,lcd_tri_o_8,lcd_tri_o_7,lcd_tri_o_6,lcd_tri_o_5,lcd_tri_o_4,lcd_tri_o_3,lcd_tri_o_2,lcd_tri_o_1,lcd_tri_o_0}),
        .lcd_tri_t({lcd_tri_t_10,lcd_tri_t_9,lcd_tri_t_8,lcd_tri_t_7,lcd_tri_t_6,lcd_tri_t_5,lcd_tri_t_4,lcd_tri_t_3,lcd_tri_t_2,lcd_tri_t_1,lcd_tri_t_0}));
endmodule
