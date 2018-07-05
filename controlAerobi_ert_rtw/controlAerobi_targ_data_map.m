  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (controlAerobi_P)
    ;%
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% controlAerobi_P.DiscreteDerivative_ICPrevScaled
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_P.DiscreteDerivative_ICPrevScal_m
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controlAerobi_P.DiscreteDerivative_ICPrevScal_k
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controlAerobi_P.DiscreteDerivative_ICPrevScal_e
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controlAerobi_P.DiscreteDerivative_ICPrevScal_d
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controlAerobi_P.DiscreteDerivative_ICPrevSca_da
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controlAerobi_P.DiscreteDerivative_ICPrevScal_a
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controlAerobi_P.DiscreteDerivative_ICPrevSca_kf
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controlAerobi_P.logs_SelectPlot1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controlAerobi_P.logs_SelectPlot2
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controlAerobi_P.logs_SelectPlot3
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controlAerobi_P.logs_SelectPlot4
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controlAerobi_P.CompareToConstant1_const
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controlAerobi_P.CompareToConstant2_const
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controlAerobi_P.CompareToConstant3_const
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controlAerobi_P.CompareToConstant_const
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controlAerobi_P.CompareToConstant_const_c
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controlAerobi_P.CompareToConstant_const_d
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controlAerobi_P.CompareToConstant4_const
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controlAerobi_P.CompareToConstant_const_h
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controlAerobi_P.CompareToConstant_const_h5
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controlAerobi_P.CompareToConstant_const_p
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controlAerobi_P.CompareToConstant_const_l
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controlAerobi_P.CompareToConstant_const_b
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controlAerobi_P.CompareToConstant_const_m
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% controlAerobi_P.CompareToConstant_const_e
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% controlAerobi_P.CompareToConstant_const_i
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% controlAerobi_P.CompareToConstant_const_hw
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% controlAerobi_P.CompareToConstant_const_g
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% controlAerobi_P.CompareToConstant_const_bo
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controlAerobi_P.PX4receive_localPort
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_P.Localpositionreceive_localPort
	  section.data(2).logicalSrcIdx = 31;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 326;
      section.data(326)  = dumData; %prealloc
      
	  ;% controlAerobi_P.Reset_Value
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_P.Saturation_UpperSat
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 4;
	
	  ;% controlAerobi_P.Saturation_LowerSat
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 5;
	
	  ;% controlAerobi_P.Xdes_Value
	  section.data(4).logicalSrcIdx = 35;
	  section.data(4).dtTransOffset = 6;
	
	  ;% controlAerobi_P.Ydes_Value
	  section.data(5).logicalSrcIdx = 36;
	  section.data(5).dtTransOffset = 7;
	
	  ;% controlAerobi_P.zero_Value
	  section.data(6).logicalSrcIdx = 37;
	  section.data(6).dtTransOffset = 8;
	
	  ;% controlAerobi_P.Saturation1_UpperSat
	  section.data(7).logicalSrcIdx = 38;
	  section.data(7).dtTransOffset = 9;
	
	  ;% controlAerobi_P.Saturation1_LowerSat
	  section.data(8).logicalSrcIdx = 39;
	  section.data(8).dtTransOffset = 10;
	
	  ;% controlAerobi_P.Constant_Value
	  section.data(9).logicalSrcIdx = 40;
	  section.data(9).dtTransOffset = 11;
	
	  ;% controlAerobi_P.Saturation2_UpperSat
	  section.data(10).logicalSrcIdx = 41;
	  section.data(10).dtTransOffset = 12;
	
	  ;% controlAerobi_P.Saturation2_LowerSat
	  section.data(11).logicalSrcIdx = 42;
	  section.data(11).dtTransOffset = 13;
	
	  ;% controlAerobi_P.Gain_Gain
	  section.data(12).logicalSrcIdx = 43;
	  section.data(12).dtTransOffset = 14;
	
	  ;% controlAerobi_P.Gain1_Gain
	  section.data(13).logicalSrcIdx = 44;
	  section.data(13).dtTransOffset = 15;
	
	  ;% controlAerobi_P.Constant1_Value
	  section.data(14).logicalSrcIdx = 45;
	  section.data(14).dtTransOffset = 16;
	
	  ;% controlAerobi_P.Constant1_Value_o
	  section.data(15).logicalSrcIdx = 46;
	  section.data(15).dtTransOffset = 17;
	
	  ;% controlAerobi_P.I_Yaw_rate_Value
	  section.data(16).logicalSrcIdx = 47;
	  section.data(16).dtTransOffset = 18;
	
	  ;% controlAerobi_P.SatNeg_Yaw_rate_Value
	  section.data(17).logicalSrcIdx = 48;
	  section.data(17).dtTransOffset = 19;
	
	  ;% controlAerobi_P.Constant1_Value_h
	  section.data(18).logicalSrcIdx = 49;
	  section.data(18).dtTransOffset = 20;
	
	  ;% controlAerobi_P.Constant1_Value_j
	  section.data(19).logicalSrcIdx = 50;
	  section.data(19).dtTransOffset = 21;
	
	  ;% controlAerobi_P.Constant_Value_k
	  section.data(20).logicalSrcIdx = 51;
	  section.data(20).dtTransOffset = 22;
	
	  ;% controlAerobi_P.SatNeg_Yaw_pos_Value
	  section.data(21).logicalSrcIdx = 52;
	  section.data(21).dtTransOffset = 23;
	
	  ;% controlAerobi_P.Constant1_Value_m
	  section.data(22).logicalSrcIdx = 53;
	  section.data(22).dtTransOffset = 24;
	
	  ;% controlAerobi_P.Constant1_Value_l
	  section.data(23).logicalSrcIdx = 54;
	  section.data(23).dtTransOffset = 25;
	
	  ;% controlAerobi_P.zero_Value_n
	  section.data(24).logicalSrcIdx = 55;
	  section.data(24).dtTransOffset = 26;
	
	  ;% controlAerobi_P.SatNeg_Z_pos_Value
	  section.data(25).logicalSrcIdx = 56;
	  section.data(25).dtTransOffset = 27;
	
	  ;% controlAerobi_P.SatNeg_Z_rate_Value
	  section.data(26).logicalSrcIdx = 57;
	  section.data(26).dtTransOffset = 28;
	
	  ;% controlAerobi_P.Saturation_UpperSat_a
	  section.data(27).logicalSrcIdx = 58;
	  section.data(27).dtTransOffset = 29;
	
	  ;% controlAerobi_P.Saturation_LowerSat_f
	  section.data(28).logicalSrcIdx = 59;
	  section.data(28).dtTransOffset = 30;
	
	  ;% controlAerobi_P.Constant_Value_a
	  section.data(29).logicalSrcIdx = 60;
	  section.data(29).dtTransOffset = 31;
	
	  ;% controlAerobi_P.Constant2_Value
	  section.data(30).logicalSrcIdx = 61;
	  section.data(30).dtTransOffset = 32;
	
	  ;% controlAerobi_P.Constant1_Value_f
	  section.data(31).logicalSrcIdx = 62;
	  section.data(31).dtTransOffset = 33;
	
	  ;% controlAerobi_P.Constant2_Value_n
	  section.data(32).logicalSrcIdx = 63;
	  section.data(32).dtTransOffset = 34;
	
	  ;% controlAerobi_P.offset_Value
	  section.data(33).logicalSrcIdx = 64;
	  section.data(33).dtTransOffset = 35;
	
	  ;% controlAerobi_P.Gain_Gain_l
	  section.data(34).logicalSrcIdx = 65;
	  section.data(34).dtTransOffset = 38;
	
	  ;% controlAerobi_P.Constant_Value_ab
	  section.data(35).logicalSrcIdx = 66;
	  section.data(35).dtTransOffset = 39;
	
	  ;% controlAerobi_P.Constant_Value_h
	  section.data(36).logicalSrcIdx = 67;
	  section.data(36).dtTransOffset = 43;
	
	  ;% controlAerobi_P.Constant_Value_c
	  section.data(37).logicalSrcIdx = 68;
	  section.data(37).dtTransOffset = 44;
	
	  ;% controlAerobi_P.Constant_Value_m
	  section.data(38).logicalSrcIdx = 69;
	  section.data(38).dtTransOffset = 45;
	
	  ;% controlAerobi_P.Gain1_Gain_p
	  section.data(39).logicalSrcIdx = 70;
	  section.data(39).dtTransOffset = 46;
	
	  ;% controlAerobi_P.Gain_Gain_b
	  section.data(40).logicalSrcIdx = 71;
	  section.data(40).dtTransOffset = 47;
	
	  ;% controlAerobi_P.select_xy_px1_Value
	  section.data(41).logicalSrcIdx = 72;
	  section.data(41).dtTransOffset = 48;
	
	  ;% controlAerobi_P.select_xy_px4_Value
	  section.data(42).logicalSrcIdx = 73;
	  section.data(42).dtTransOffset = 49;
	
	  ;% controlAerobi_P.selector_xy_ekf_Value
	  section.data(43).logicalSrcIdx = 74;
	  section.data(43).dtTransOffset = 50;
	
	  ;% controlAerobi_P.Constant_Value_o
	  section.data(44).logicalSrcIdx = 75;
	  section.data(44).dtTransOffset = 51;
	
	  ;% controlAerobi_P.Constant1_Value_k
	  section.data(45).logicalSrcIdx = 76;
	  section.data(45).dtTransOffset = 52;
	
	  ;% controlAerobi_P.select_Value
	  section.data(46).logicalSrcIdx = 77;
	  section.data(46).dtTransOffset = 53;
	
	  ;% controlAerobi_P.Switch_Threshold
	  section.data(47).logicalSrcIdx = 78;
	  section.data(47).dtTransOffset = 54;
	
	  ;% controlAerobi_P.RotationAnglescorrection_Gain
	  section.data(48).logicalSrcIdx = 79;
	  section.data(48).dtTransOffset = 55;
	
	  ;% controlAerobi_P.Mgyro_Value
	  section.data(49).logicalSrcIdx = 80;
	  section.data(49).dtTransOffset = 64;
	
	  ;% controlAerobi_P.Biasgyro_Value
	  section.data(50).logicalSrcIdx = 81;
	  section.data(50).dtTransOffset = 73;
	
	  ;% controlAerobi_P.reset_Value
	  section.data(51).logicalSrcIdx = 82;
	  section.data(51).dtTransOffset = 76;
	
	  ;% controlAerobi_P.Maccel_Value
	  section.data(52).logicalSrcIdx = 83;
	  section.data(52).dtTransOffset = 77;
	
	  ;% controlAerobi_P.Biasaccel_Value
	  section.data(53).logicalSrcIdx = 84;
	  section.data(53).dtTransOffset = 86;
	
	  ;% controlAerobi_P.Constant_Value_p
	  section.data(54).logicalSrcIdx = 85;
	  section.data(54).dtTransOffset = 89;
	
	  ;% controlAerobi_P.Mmagnet_Value
	  section.data(55).logicalSrcIdx = 86;
	  section.data(55).dtTransOffset = 92;
	
	  ;% controlAerobi_P.Biasmagnet_Value
	  section.data(56).logicalSrcIdx = 87;
	  section.data(56).dtTransOffset = 101;
	
	  ;% controlAerobi_P.kb_Value
	  section.data(57).logicalSrcIdx = 88;
	  section.data(57).dtTransOffset = 104;
	
	  ;% controlAerobi_P.k1_Value
	  section.data(58).logicalSrcIdx = 89;
	  section.data(58).dtTransOffset = 105;
	
	  ;% controlAerobi_P.k2_Value
	  section.data(59).logicalSrcIdx = 90;
	  section.data(59).dtTransOffset = 106;
	
	  ;% controlAerobi_P.k3_Value
	  section.data(60).logicalSrcIdx = 91;
	  section.data(60).dtTransOffset = 107;
	
	  ;% controlAerobi_P.k4_Value
	  section.data(61).logicalSrcIdx = 92;
	  section.data(61).dtTransOffset = 108;
	
	  ;% controlAerobi_P.limit_Value
	  section.data(62).logicalSrcIdx = 93;
	  section.data(62).dtTransOffset = 109;
	
	  ;% controlAerobi_P.Mgyro_Value_f
	  section.data(63).logicalSrcIdx = 94;
	  section.data(63).dtTransOffset = 110;
	
	  ;% controlAerobi_P.Biasgyro_Value_n
	  section.data(64).logicalSrcIdx = 95;
	  section.data(64).dtTransOffset = 119;
	
	  ;% controlAerobi_P.Maccel_Value_p
	  section.data(65).logicalSrcIdx = 96;
	  section.data(65).dtTransOffset = 122;
	
	  ;% controlAerobi_P.Biasaccel_Value_e
	  section.data(66).logicalSrcIdx = 97;
	  section.data(66).dtTransOffset = 131;
	
	  ;% controlAerobi_P.RateLimiter1_RisingLim
	  section.data(67).logicalSrcIdx = 98;
	  section.data(67).dtTransOffset = 134;
	
	  ;% controlAerobi_P.RateLimiter1_FallingLim
	  section.data(68).logicalSrcIdx = 99;
	  section.data(68).dtTransOffset = 135;
	
	  ;% controlAerobi_P.RateLimiter1_IC
	  section.data(69).logicalSrcIdx = 100;
	  section.data(69).dtTransOffset = 136;
	
	  ;% controlAerobi_P.Constant_Value_l
	  section.data(70).logicalSrcIdx = 101;
	  section.data(70).dtTransOffset = 137;
	
	  ;% controlAerobi_P.Mmagnet_Value_c
	  section.data(71).logicalSrcIdx = 102;
	  section.data(71).dtTransOffset = 140;
	
	  ;% controlAerobi_P.Biasmagnet_Value_k
	  section.data(72).logicalSrcIdx = 103;
	  section.data(72).dtTransOffset = 149;
	
	  ;% controlAerobi_P.RateLimiter1_RisingLim_p
	  section.data(73).logicalSrcIdx = 104;
	  section.data(73).dtTransOffset = 152;
	
	  ;% controlAerobi_P.RateLimiter1_FallingLim_l
	  section.data(74).logicalSrcIdx = 105;
	  section.data(74).dtTransOffset = 153;
	
	  ;% controlAerobi_P.RateLimiter1_IC_i
	  section.data(75).logicalSrcIdx = 106;
	  section.data(75).dtTransOffset = 154;
	
	  ;% controlAerobi_P.kb_Value_o
	  section.data(76).logicalSrcIdx = 107;
	  section.data(76).dtTransOffset = 155;
	
	  ;% controlAerobi_P.k1_Value_l
	  section.data(77).logicalSrcIdx = 108;
	  section.data(77).dtTransOffset = 156;
	
	  ;% controlAerobi_P.k2_Value_a
	  section.data(78).logicalSrcIdx = 109;
	  section.data(78).dtTransOffset = 157;
	
	  ;% controlAerobi_P.k3_Value_j
	  section.data(79).logicalSrcIdx = 110;
	  section.data(79).dtTransOffset = 158;
	
	  ;% controlAerobi_P.k4_Value_j
	  section.data(80).logicalSrcIdx = 111;
	  section.data(80).dtTransOffset = 159;
	
	  ;% controlAerobi_P.limit_Value_b
	  section.data(81).logicalSrcIdx = 112;
	  section.data(81).dtTransOffset = 160;
	
	  ;% controlAerobi_P.Constant_Value_g
	  section.data(82).logicalSrcIdx = 113;
	  section.data(82).dtTransOffset = 161;
	
	  ;% controlAerobi_P.offset_Value_h
	  section.data(83).logicalSrcIdx = 114;
	  section.data(83).dtTransOffset = 162;
	
	  ;% controlAerobi_P.Gain_Gain_i
	  section.data(84).logicalSrcIdx = 115;
	  section.data(84).dtTransOffset = 165;
	
	  ;% controlAerobi_P.M_accel_Value
	  section.data(85).logicalSrcIdx = 116;
	  section.data(85).dtTransOffset = 166;
	
	  ;% controlAerobi_P.RateLimiter_RisingLim
	  section.data(86).logicalSrcIdx = 117;
	  section.data(86).dtTransOffset = 175;
	
	  ;% controlAerobi_P.RateLimiter_FallingLim
	  section.data(87).logicalSrcIdx = 118;
	  section.data(87).dtTransOffset = 176;
	
	  ;% controlAerobi_P.RateLimiter_IC
	  section.data(88).logicalSrcIdx = 119;
	  section.data(88).dtTransOffset = 177;
	
	  ;% controlAerobi_P.Bias_accel_Value
	  section.data(89).logicalSrcIdx = 120;
	  section.data(89).dtTransOffset = 178;
	
	  ;% controlAerobi_P.M_gyro_Value
	  section.data(90).logicalSrcIdx = 121;
	  section.data(90).dtTransOffset = 181;
	
	  ;% controlAerobi_P.Bias_gyro_Value
	  section.data(91).logicalSrcIdx = 122;
	  section.data(91).dtTransOffset = 190;
	
	  ;% controlAerobi_P.M_magnet_Value
	  section.data(92).logicalSrcIdx = 123;
	  section.data(92).dtTransOffset = 193;
	
	  ;% controlAerobi_P.Constant_Value_f
	  section.data(93).logicalSrcIdx = 124;
	  section.data(93).dtTransOffset = 202;
	
	  ;% controlAerobi_P.RateLimiter1_RisingLim_n
	  section.data(94).logicalSrcIdx = 125;
	  section.data(94).dtTransOffset = 205;
	
	  ;% controlAerobi_P.RateLimiter1_FallingLim_i
	  section.data(95).logicalSrcIdx = 126;
	  section.data(95).dtTransOffset = 206;
	
	  ;% controlAerobi_P.RateLimiter1_IC_iz
	  section.data(96).logicalSrcIdx = 127;
	  section.data(96).dtTransOffset = 207;
	
	  ;% controlAerobi_P.Gain_Gain_j
	  section.data(97).logicalSrcIdx = 128;
	  section.data(97).dtTransOffset = 208;
	
	  ;% controlAerobi_P.Bias_magnet_Value
	  section.data(98).logicalSrcIdx = 129;
	  section.data(98).dtTransOffset = 209;
	
	  ;% controlAerobi_P.mu_a_Value
	  section.data(99).logicalSrcIdx = 130;
	  section.data(99).dtTransOffset = 212;
	
	  ;% controlAerobi_P.mu_m_Value
	  section.data(100).logicalSrcIdx = 131;
	  section.data(100).dtTransOffset = 213;
	
	  ;% controlAerobi_P.rk_Value
	  section.data(101).logicalSrcIdx = 132;
	  section.data(101).dtTransOffset = 214;
	
	  ;% controlAerobi_P.qk_Value
	  section.data(102).logicalSrcIdx = 133;
	  section.data(102).dtTransOffset = 220;
	
	  ;% controlAerobi_P.mu_Value
	  section.data(103).logicalSrcIdx = 134;
	  section.data(103).dtTransOffset = 230;
	
	  ;% controlAerobi_P.chi_Value
	  section.data(104).logicalSrcIdx = 135;
	  section.data(104).dtTransOffset = 231;
	
	  ;% controlAerobi_P.p0_Value
	  section.data(105).logicalSrcIdx = 136;
	  section.data(105).dtTransOffset = 232;
	
	  ;% controlAerobi_P.distorsion_max_Value
	  section.data(106).logicalSrcIdx = 137;
	  section.data(106).dtTransOffset = 233;
	
	  ;% controlAerobi_P.ym_Value
	  section.data(107).logicalSrcIdx = 138;
	  section.data(107).dtTransOffset = 234;
	
	  ;% controlAerobi_P.ya_Value
	  section.data(108).logicalSrcIdx = 139;
	  section.data(108).dtTransOffset = 235;
	
	  ;% controlAerobi_P.weight_Value
	  section.data(109).logicalSrcIdx = 140;
	  section.data(109).dtTransOffset = 236;
	
	  ;% controlAerobi_P.distorsion_max_Value_g
	  section.data(110).logicalSrcIdx = 141;
	  section.data(110).dtTransOffset = 237;
	
	  ;% controlAerobi_P.er_Value
	  section.data(111).logicalSrcIdx = 142;
	  section.data(111).dtTransOffset = 238;
	
	  ;% controlAerobi_P.NEDENU_Value
	  section.data(112).logicalSrcIdx = 143;
	  section.data(112).dtTransOffset = 239;
	
	  ;% controlAerobi_P.Gain2_Gain
	  section.data(113).logicalSrcIdx = 144;
	  section.data(113).dtTransOffset = 240;
	
	  ;% controlAerobi_P.Constant4_Value
	  section.data(114).logicalSrcIdx = 145;
	  section.data(114).dtTransOffset = 241;
	
	  ;% controlAerobi_P.Constant5_Value
	  section.data(115).logicalSrcIdx = 146;
	  section.data(115).dtTransOffset = 242;
	
	  ;% controlAerobi_P.RateLimiter_RisingLim_g
	  section.data(116).logicalSrcIdx = 147;
	  section.data(116).dtTransOffset = 243;
	
	  ;% controlAerobi_P.RateLimiter_FallingLim_k
	  section.data(117).logicalSrcIdx = 148;
	  section.data(117).dtTransOffset = 244;
	
	  ;% controlAerobi_P.RateLimiter_IC_a
	  section.data(118).logicalSrcIdx = 149;
	  section.data(118).dtTransOffset = 245;
	
	  ;% controlAerobi_P.RateLimiter1_RisingLim_i
	  section.data(119).logicalSrcIdx = 150;
	  section.data(119).dtTransOffset = 246;
	
	  ;% controlAerobi_P.RateLimiter1_FallingLim_o
	  section.data(120).logicalSrcIdx = 151;
	  section.data(120).dtTransOffset = 247;
	
	  ;% controlAerobi_P.RateLimiter1_IC_b
	  section.data(121).logicalSrcIdx = 152;
	  section.data(121).dtTransOffset = 248;
	
	  ;% controlAerobi_P.RateLimiter2_RisingLim
	  section.data(122).logicalSrcIdx = 153;
	  section.data(122).dtTransOffset = 249;
	
	  ;% controlAerobi_P.RateLimiter2_FallingLim
	  section.data(123).logicalSrcIdx = 154;
	  section.data(123).dtTransOffset = 250;
	
	  ;% controlAerobi_P.RateLimiter2_IC
	  section.data(124).logicalSrcIdx = 155;
	  section.data(124).dtTransOffset = 251;
	
	  ;% controlAerobi_P.RateLimiter3_RisingLim
	  section.data(125).logicalSrcIdx = 156;
	  section.data(125).dtTransOffset = 252;
	
	  ;% controlAerobi_P.RateLimiter3_FallingLim
	  section.data(126).logicalSrcIdx = 157;
	  section.data(126).dtTransOffset = 253;
	
	  ;% controlAerobi_P.RateLimiter3_IC
	  section.data(127).logicalSrcIdx = 158;
	  section.data(127).dtTransOffset = 254;
	
	  ;% controlAerobi_P.d_sf11_Value
	  section.data(128).logicalSrcIdx = 159;
	  section.data(128).dtTransOffset = 255;
	
	  ;% controlAerobi_P.KQ_Value
	  section.data(129).logicalSrcIdx = 160;
	  section.data(129).dtTransOffset = 256;
	
	  ;% controlAerobi_P.KR_Value
	  section.data(130).logicalSrcIdx = 161;
	  section.data(130).dtTransOffset = 262;
	
	  ;% controlAerobi_P.selector_z_Value
	  section.data(131).logicalSrcIdx = 162;
	  section.data(131).dtTransOffset = 267;
	
	  ;% controlAerobi_P.Gain1_Gain_a
	  section.data(132).logicalSrcIdx = 163;
	  section.data(132).dtTransOffset = 268;
	
	  ;% controlAerobi_P.Gain_Gain_p
	  section.data(133).logicalSrcIdx = 164;
	  section.data(133).dtTransOffset = 269;
	
	  ;% controlAerobi_P.Gain2_Gain_k
	  section.data(134).logicalSrcIdx = 165;
	  section.data(134).dtTransOffset = 270;
	
	  ;% controlAerobi_P.Gain4_Gain
	  section.data(135).logicalSrcIdx = 166;
	  section.data(135).dtTransOffset = 271;
	
	  ;% controlAerobi_P.Zdes_Value
	  section.data(136).logicalSrcIdx = 167;
	  section.data(136).dtTransOffset = 272;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_gainval
	  section.data(137).logicalSrcIdx = 168;
	  section.data(137).dtTransOffset = 273;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_IC
	  section.data(138).logicalSrcIdx = 169;
	  section.data(138).dtTransOffset = 274;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_gainva_i
	  section.data(139).logicalSrcIdx = 170;
	  section.data(139).dtTransOffset = 275;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_IC_d
	  section.data(140).logicalSrcIdx = 171;
	  section.data(140).dtTransOffset = 276;
	
	  ;% controlAerobi_P.Saturation_UpperSat_p
	  section.data(141).logicalSrcIdx = 172;
	  section.data(141).dtTransOffset = 277;
	
	  ;% controlAerobi_P.Saturation_LowerSat_k
	  section.data(142).logicalSrcIdx = 173;
	  section.data(142).dtTransOffset = 278;
	
	  ;% controlAerobi_P.Gain2_Gain_i
	  section.data(143).logicalSrcIdx = 174;
	  section.data(143).dtTransOffset = 279;
	
	  ;% controlAerobi_P.Gain1_Gain_al
	  section.data(144).logicalSrcIdx = 175;
	  section.data(144).dtTransOffset = 280;
	
	  ;% controlAerobi_P.b1_Value
	  section.data(145).logicalSrcIdx = 176;
	  section.data(145).dtTransOffset = 281;
	
	  ;% controlAerobi_P.Gain_Gain_c
	  section.data(146).logicalSrcIdx = 177;
	  section.data(146).dtTransOffset = 284;
	
	  ;% controlAerobi_P.k_x_Value
	  section.data(147).logicalSrcIdx = 178;
	  section.data(147).dtTransOffset = 285;
	
	  ;% controlAerobi_P.k_v_Value
	  section.data(148).logicalSrcIdx = 179;
	  section.data(148).dtTransOffset = 288;
	
	  ;% controlAerobi_P.k_i_Value
	  section.data(149).logicalSrcIdx = 180;
	  section.data(149).dtTransOffset = 291;
	
	  ;% controlAerobi_P.c1_Value
	  section.data(150).logicalSrcIdx = 181;
	  section.data(150).dtTransOffset = 294;
	
	  ;% controlAerobi_P.sat_P_Value
	  section.data(151).logicalSrcIdx = 182;
	  section.data(151).dtTransOffset = 297;
	
	  ;% controlAerobi_P.Mass_Value
	  section.data(152).logicalSrcIdx = 183;
	  section.data(152).dtTransOffset = 300;
	
	  ;% controlAerobi_P.Gain_Gain_b5
	  section.data(153).logicalSrcIdx = 184;
	  section.data(153).dtTransOffset = 301;
	
	  ;% controlAerobi_P.Hlp_InitialStates
	  section.data(154).logicalSrcIdx = 185;
	  section.data(154).dtTransOffset = 302;
	
	  ;% controlAerobi_P.Hlp_Coefficients
	  section.data(155).logicalSrcIdx = 186;
	  section.data(155).dtTransOffset = 303;
	
	  ;% controlAerobi_P.Gain_Gain_n
	  section.data(156).logicalSrcIdx = 187;
	  section.data(156).dtTransOffset = 314;
	
	  ;% controlAerobi_P.Constant_Value_k1
	  section.data(157).logicalSrcIdx = 188;
	  section.data(157).dtTransOffset = 315;
	
	  ;% controlAerobi_P.Constant1_Value_e
	  section.data(158).logicalSrcIdx = 189;
	  section.data(158).dtTransOffset = 316;
	
	  ;% controlAerobi_P.Saturation2_UpperSat_l
	  section.data(159).logicalSrcIdx = 190;
	  section.data(159).dtTransOffset = 317;
	
	  ;% controlAerobi_P.Saturation2_LowerSat_h
	  section.data(160).logicalSrcIdx = 191;
	  section.data(160).dtTransOffset = 318;
	
	  ;% controlAerobi_P.Gain4_Gain_f
	  section.data(161).logicalSrcIdx = 192;
	  section.data(161).dtTransOffset = 319;
	
	  ;% controlAerobi_P.Gain1_Gain_f
	  section.data(162).logicalSrcIdx = 193;
	  section.data(162).dtTransOffset = 320;
	
	  ;% controlAerobi_P.Constant2_Value_f
	  section.data(163).logicalSrcIdx = 194;
	  section.data(163).dtTransOffset = 321;
	
	  ;% controlAerobi_P.Gain4_Gain_b
	  section.data(164).logicalSrcIdx = 195;
	  section.data(164).dtTransOffset = 322;
	
	  ;% controlAerobi_P.Saturation1_UpperSat_n
	  section.data(165).logicalSrcIdx = 196;
	  section.data(165).dtTransOffset = 323;
	
	  ;% controlAerobi_P.Saturation1_LowerSat_b
	  section.data(166).logicalSrcIdx = 197;
	  section.data(166).dtTransOffset = 324;
	
	  ;% controlAerobi_P.Gain3_Gain
	  section.data(167).logicalSrcIdx = 198;
	  section.data(167).dtTransOffset = 325;
	
	  ;% controlAerobi_P.Gain3_Gain_m
	  section.data(168).logicalSrcIdx = 199;
	  section.data(168).dtTransOffset = 326;
	
	  ;% controlAerobi_P.Constant6_Value
	  section.data(169).logicalSrcIdx = 200;
	  section.data(169).dtTransOffset = 327;
	
	  ;% controlAerobi_P.Constant7_Value
	  section.data(170).logicalSrcIdx = 201;
	  section.data(170).dtTransOffset = 328;
	
	  ;% controlAerobi_P.Gain5_Gain
	  section.data(171).logicalSrcIdx = 202;
	  section.data(171).dtTransOffset = 329;
	
	  ;% controlAerobi_P.Gain1_Gain_l
	  section.data(172).logicalSrcIdx = 203;
	  section.data(172).dtTransOffset = 330;
	
	  ;% controlAerobi_P.Gain2_Gain_b
	  section.data(173).logicalSrcIdx = 204;
	  section.data(173).dtTransOffset = 331;
	
	  ;% controlAerobi_P.Gain_Gain_n5
	  section.data(174).logicalSrcIdx = 205;
	  section.data(174).dtTransOffset = 332;
	
	  ;% controlAerobi_P.J_Value
	  section.data(175).logicalSrcIdx = 206;
	  section.data(175).dtTransOffset = 333;
	
	  ;% controlAerobi_P.k_R_Value
	  section.data(176).logicalSrcIdx = 207;
	  section.data(176).dtTransOffset = 342;
	
	  ;% controlAerobi_P.k_Omega_Value
	  section.data(177).logicalSrcIdx = 208;
	  section.data(177).dtTransOffset = 345;
	
	  ;% controlAerobi_P.k_I_Value
	  section.data(178).logicalSrcIdx = 209;
	  section.data(178).dtTransOffset = 348;
	
	  ;% controlAerobi_P.c2_Value
	  section.data(179).logicalSrcIdx = 210;
	  section.data(179).dtTransOffset = 351;
	
	  ;% controlAerobi_P.sat_R_Value
	  section.data(180).logicalSrcIdx = 211;
	  section.data(180).dtTransOffset = 354;
	
	  ;% controlAerobi_P.drift_Value
	  section.data(181).logicalSrcIdx = 212;
	  section.data(181).dtTransOffset = 357;
	
	  ;% controlAerobi_P.SatPos_Z_rate_Value
	  section.data(182).logicalSrcIdx = 213;
	  section.data(182).dtTransOffset = 360;
	
	  ;% controlAerobi_P.P_Z_rate_Value
	  section.data(183).logicalSrcIdx = 214;
	  section.data(183).dtTransOffset = 361;
	
	  ;% controlAerobi_P.SatPos_Z_pos_Value
	  section.data(184).logicalSrcIdx = 215;
	  section.data(184).dtTransOffset = 362;
	
	  ;% controlAerobi_P.P_Z_pos_Value
	  section.data(185).logicalSrcIdx = 216;
	  section.data(185).dtTransOffset = 363;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_gainva_a
	  section.data(186).logicalSrcIdx = 217;
	  section.data(186).dtTransOffset = 364;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_IC_l
	  section.data(187).logicalSrcIdx = 218;
	  section.data(187).dtTransOffset = 365;
	
	  ;% controlAerobi_P.Saturation_UpperSat_n
	  section.data(188).logicalSrcIdx = 219;
	  section.data(188).dtTransOffset = 366;
	
	  ;% controlAerobi_P.Saturation_LowerSat_e
	  section.data(189).logicalSrcIdx = 220;
	  section.data(189).dtTransOffset = 367;
	
	  ;% controlAerobi_P.Constant_Value_oa
	  section.data(190).logicalSrcIdx = 221;
	  section.data(190).dtTransOffset = 368;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_gainva_e
	  section.data(191).logicalSrcIdx = 222;
	  section.data(191).dtTransOffset = 369;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_IC_df
	  section.data(192).logicalSrcIdx = 223;
	  section.data(192).dtTransOffset = 370;
	
	  ;% controlAerobi_P.D_Z_pos_Value
	  section.data(193).logicalSrcIdx = 224;
	  section.data(193).dtTransOffset = 371;
	
	  ;% controlAerobi_P.TSamp_WtEt
	  section.data(194).logicalSrcIdx = 225;
	  section.data(194).dtTransOffset = 372;
	
	  ;% controlAerobi_P.med_thrust_Value
	  section.data(195).logicalSrcIdx = 226;
	  section.data(195).dtTransOffset = 373;
	
	  ;% controlAerobi_P.adapt_thrust_Gain
	  section.data(196).logicalSrcIdx = 227;
	  section.data(196).dtTransOffset = 374;
	
	  ;% controlAerobi_P.uDLookupTable_tableData
	  section.data(197).logicalSrcIdx = 228;
	  section.data(197).dtTransOffset = 375;
	
	  ;% controlAerobi_P.uDLookupTable_bp01Data
	  section.data(198).logicalSrcIdx = 229;
	  section.data(198).dtTransOffset = 976;
	
	  ;% controlAerobi_P.dZgain_Gain
	  section.data(199).logicalSrcIdx = 230;
	  section.data(199).dtTransOffset = 1577;
	
	  ;% controlAerobi_P.DeadZone_Start
	  section.data(200).logicalSrcIdx = 231;
	  section.data(200).dtTransOffset = 1578;
	
	  ;% controlAerobi_P.DeadZone_End
	  section.data(201).logicalSrcIdx = 232;
	  section.data(201).dtTransOffset = 1579;
	
	  ;% controlAerobi_P.Saturation_UpperSat_g
	  section.data(202).logicalSrcIdx = 233;
	  section.data(202).dtTransOffset = 1580;
	
	  ;% controlAerobi_P.Saturation_LowerSat_o
	  section.data(203).logicalSrcIdx = 234;
	  section.data(203).dtTransOffset = 1581;
	
	  ;% controlAerobi_P.Constant_Value_b
	  section.data(204).logicalSrcIdx = 235;
	  section.data(204).dtTransOffset = 1582;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_gainva_m
	  section.data(205).logicalSrcIdx = 236;
	  section.data(205).dtTransOffset = 1583;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_IC_p
	  section.data(206).logicalSrcIdx = 237;
	  section.data(206).dtTransOffset = 1584;
	
	  ;% controlAerobi_P.D_Z_rate_Value
	  section.data(207).logicalSrcIdx = 238;
	  section.data(207).dtTransOffset = 1585;
	
	  ;% controlAerobi_P.TSamp_WtEt_g
	  section.data(208).logicalSrcIdx = 239;
	  section.data(208).dtTransOffset = 1586;
	
	  ;% controlAerobi_P.Gain1_Gain_m
	  section.data(209).logicalSrcIdx = 240;
	  section.data(209).dtTransOffset = 1587;
	
	  ;% controlAerobi_P.Constant8_Value
	  section.data(210).logicalSrcIdx = 241;
	  section.data(210).dtTransOffset = 1588;
	
	  ;% controlAerobi_P.SatPos_RollPitch_rate_Value
	  section.data(211).logicalSrcIdx = 242;
	  section.data(211).dtTransOffset = 1589;
	
	  ;% controlAerobi_P.P_RollPitch_rate_Value
	  section.data(212).logicalSrcIdx = 243;
	  section.data(212).dtTransOffset = 1590;
	
	  ;% controlAerobi_P.SatPos_RollPitch_pos_Value
	  section.data(213).logicalSrcIdx = 244;
	  section.data(213).dtTransOffset = 1591;
	
	  ;% controlAerobi_P.P_RollPitch_pos_Value
	  section.data(214).logicalSrcIdx = 245;
	  section.data(214).dtTransOffset = 1592;
	
	  ;% controlAerobi_P.Gain_Gain_e
	  section.data(215).logicalSrcIdx = 246;
	  section.data(215).dtTransOffset = 1593;
	
	  ;% controlAerobi_P.SatPos_XY_pos_Value
	  section.data(216).logicalSrcIdx = 247;
	  section.data(216).dtTransOffset = 1594;
	
	  ;% controlAerobi_P.P_XY_pos_Value
	  section.data(217).logicalSrcIdx = 248;
	  section.data(217).dtTransOffset = 1595;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_gainv_mu
	  section.data(218).logicalSrcIdx = 249;
	  section.data(218).dtTransOffset = 1596;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_IC_h
	  section.data(219).logicalSrcIdx = 250;
	  section.data(219).dtTransOffset = 1597;
	
	  ;% controlAerobi_P.Saturation_UpperSat_pm
	  section.data(220).logicalSrcIdx = 251;
	  section.data(220).dtTransOffset = 1598;
	
	  ;% controlAerobi_P.Saturation_LowerSat_l
	  section.data(221).logicalSrcIdx = 252;
	  section.data(221).dtTransOffset = 1599;
	
	  ;% controlAerobi_P.DeadZone_Start_i
	  section.data(222).logicalSrcIdx = 253;
	  section.data(222).dtTransOffset = 1600;
	
	  ;% controlAerobi_P.DeadZone_End_b
	  section.data(223).logicalSrcIdx = 254;
	  section.data(223).dtTransOffset = 1601;
	
	  ;% controlAerobi_P.Gain_Gain_h
	  section.data(224).logicalSrcIdx = 255;
	  section.data(224).dtTransOffset = 1602;
	
	  ;% controlAerobi_P.DeadZone1_Start
	  section.data(225).logicalSrcIdx = 256;
	  section.data(225).dtTransOffset = 1603;
	
	  ;% controlAerobi_P.DeadZone1_End
	  section.data(226).logicalSrcIdx = 257;
	  section.data(226).dtTransOffset = 1604;
	
	  ;% controlAerobi_P.Gain1_Gain_k
	  section.data(227).logicalSrcIdx = 258;
	  section.data(227).dtTransOffset = 1605;
	
	  ;% controlAerobi_P.Saturation1_UpperSat_m
	  section.data(228).logicalSrcIdx = 259;
	  section.data(228).dtTransOffset = 1606;
	
	  ;% controlAerobi_P.Saturation1_LowerSat_f
	  section.data(229).logicalSrcIdx = 260;
	  section.data(229).dtTransOffset = 1607;
	
	  ;% controlAerobi_P.adapt_thrust_Gain_l
	  section.data(230).logicalSrcIdx = 261;
	  section.data(230).dtTransOffset = 1608;
	
	  ;% controlAerobi_P.uDLookupTable_tableData_l
	  section.data(231).logicalSrcIdx = 262;
	  section.data(231).dtTransOffset = 1609;
	
	  ;% controlAerobi_P.uDLookupTable_bp01Data_p
	  section.data(232).logicalSrcIdx = 263;
	  section.data(232).dtTransOffset = 2210;
	
	  ;% controlAerobi_P.dZgain_Gain_l
	  section.data(233).logicalSrcIdx = 264;
	  section.data(233).dtTransOffset = 2811;
	
	  ;% controlAerobi_P.DeadZone_Start_o
	  section.data(234).logicalSrcIdx = 265;
	  section.data(234).dtTransOffset = 2812;
	
	  ;% controlAerobi_P.DeadZone_End_l
	  section.data(235).logicalSrcIdx = 266;
	  section.data(235).dtTransOffset = 2813;
	
	  ;% controlAerobi_P.Saturation_UpperSat_e
	  section.data(236).logicalSrcIdx = 267;
	  section.data(236).dtTransOffset = 2814;
	
	  ;% controlAerobi_P.Saturation_LowerSat_h
	  section.data(237).logicalSrcIdx = 268;
	  section.data(237).dtTransOffset = 2815;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_gainva_d
	  section.data(238).logicalSrcIdx = 269;
	  section.data(238).dtTransOffset = 2816;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_IC_c
	  section.data(239).logicalSrcIdx = 270;
	  section.data(239).dtTransOffset = 2817;
	
	  ;% controlAerobi_P.D_XY_pos_Value
	  section.data(240).logicalSrcIdx = 271;
	  section.data(240).dtTransOffset = 2818;
	
	  ;% controlAerobi_P.TSamp_WtEt_d
	  section.data(241).logicalSrcIdx = 272;
	  section.data(241).dtTransOffset = 2819;
	
	  ;% controlAerobi_P.SatNeg_XY_pos_Value
	  section.data(242).logicalSrcIdx = 273;
	  section.data(242).dtTransOffset = 2820;
	
	  ;% controlAerobi_P.pidpid_cascade_Value
	  section.data(243).logicalSrcIdx = 274;
	  section.data(243).dtTransOffset = 2821;
	
	  ;% controlAerobi_P.SatPos_XY_rate_Value
	  section.data(244).logicalSrcIdx = 275;
	  section.data(244).dtTransOffset = 2822;
	
	  ;% controlAerobi_P.P_XY_rate_Value
	  section.data(245).logicalSrcIdx = 276;
	  section.data(245).dtTransOffset = 2823;
	
	  ;% controlAerobi_P.Saturation_UpperSat_m
	  section.data(246).logicalSrcIdx = 277;
	  section.data(246).dtTransOffset = 2824;
	
	  ;% controlAerobi_P.Saturation_LowerSat_p
	  section.data(247).logicalSrcIdx = 278;
	  section.data(247).dtTransOffset = 2825;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_gainv_mv
	  section.data(248).logicalSrcIdx = 279;
	  section.data(248).dtTransOffset = 2826;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_IC_hz
	  section.data(249).logicalSrcIdx = 280;
	  section.data(249).dtTransOffset = 2827;
	
	  ;% controlAerobi_P.D_XY_rate_Value
	  section.data(250).logicalSrcIdx = 281;
	  section.data(250).dtTransOffset = 2828;
	
	  ;% controlAerobi_P.TSamp_WtEt_b
	  section.data(251).logicalSrcIdx = 282;
	  section.data(251).dtTransOffset = 2829;
	
	  ;% controlAerobi_P.SatNeg_XY_rate_Value
	  section.data(252).logicalSrcIdx = 283;
	  section.data(252).dtTransOffset = 2830;
	
	  ;% controlAerobi_P.r_Value
	  section.data(253).logicalSrcIdx = 284;
	  section.data(253).dtTransOffset = 2831;
	
	  ;% controlAerobi_P.p_Value
	  section.data(254).logicalSrcIdx = 285;
	  section.data(254).dtTransOffset = 2832;
	
	  ;% controlAerobi_P.r1_Value
	  section.data(255).logicalSrcIdx = 286;
	  section.data(255).dtTransOffset = 2833;
	
	  ;% controlAerobi_P.r2_Value
	  section.data(256).logicalSrcIdx = 287;
	  section.data(256).dtTransOffset = 2834;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_gainva_b
	  section.data(257).logicalSrcIdx = 288;
	  section.data(257).dtTransOffset = 2835;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_IC_f
	  section.data(258).logicalSrcIdx = 289;
	  section.data(258).dtTransOffset = 2836;
	
	  ;% controlAerobi_P.D_RollPitch_pos_Value
	  section.data(259).logicalSrcIdx = 290;
	  section.data(259).dtTransOffset = 2837;
	
	  ;% controlAerobi_P.TSamp_WtEt_n
	  section.data(260).logicalSrcIdx = 291;
	  section.data(260).dtTransOffset = 2838;
	
	  ;% controlAerobi_P.SatNeg_RollPitch_pos_Value
	  section.data(261).logicalSrcIdx = 292;
	  section.data(261).dtTransOffset = 2839;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_gainva_k
	  section.data(262).logicalSrcIdx = 293;
	  section.data(262).dtTransOffset = 2840;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_IC_ly
	  section.data(263).logicalSrcIdx = 294;
	  section.data(263).dtTransOffset = 2841;
	
	  ;% controlAerobi_P.D_RollPitch_rate_Value
	  section.data(264).logicalSrcIdx = 295;
	  section.data(264).dtTransOffset = 2842;
	
	  ;% controlAerobi_P.TSamp_WtEt_e
	  section.data(265).logicalSrcIdx = 296;
	  section.data(265).dtTransOffset = 2843;
	
	  ;% controlAerobi_P.SatNeg_RollPitch_rate_Value
	  section.data(266).logicalSrcIdx = 297;
	  section.data(266).dtTransOffset = 2844;
	
	  ;% controlAerobi_P.Constant_Value_j
	  section.data(267).logicalSrcIdx = 298;
	  section.data(267).dtTransOffset = 2845;
	
	  ;% controlAerobi_P.Gain3_Gain_l
	  section.data(268).logicalSrcIdx = 299;
	  section.data(268).dtTransOffset = 2847;
	
	  ;% controlAerobi_P.Gain5_Gain_m
	  section.data(269).logicalSrcIdx = 300;
	  section.data(269).dtTransOffset = 2848;
	
	  ;% controlAerobi_P.SatPos_Yaw_rate_Value
	  section.data(270).logicalSrcIdx = 301;
	  section.data(270).dtTransOffset = 2849;
	
	  ;% controlAerobi_P.P_Yaw_rate_Value
	  section.data(271).logicalSrcIdx = 302;
	  section.data(271).dtTransOffset = 2850;
	
	  ;% controlAerobi_P.SatPos_Yaw_pos_Value
	  section.data(272).logicalSrcIdx = 303;
	  section.data(272).dtTransOffset = 2851;
	
	  ;% controlAerobi_P.P_Yaw_pos_Value
	  section.data(273).logicalSrcIdx = 304;
	  section.data(273).dtTransOffset = 2852;
	
	  ;% controlAerobi_P.DeadZone1_Start_c
	  section.data(274).logicalSrcIdx = 305;
	  section.data(274).dtTransOffset = 2853;
	
	  ;% controlAerobi_P.DeadZone1_End_a
	  section.data(275).logicalSrcIdx = 306;
	  section.data(275).dtTransOffset = 2854;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_gainva_o
	  section.data(276).logicalSrcIdx = 307;
	  section.data(276).dtTransOffset = 2855;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_IC_cx
	  section.data(277).logicalSrcIdx = 308;
	  section.data(277).dtTransOffset = 2856;
	
	  ;% controlAerobi_P.D_Yaw_pos_Value
	  section.data(278).logicalSrcIdx = 309;
	  section.data(278).dtTransOffset = 2857;
	
	  ;% controlAerobi_P.TSamp_WtEt_o
	  section.data(279).logicalSrcIdx = 310;
	  section.data(279).dtTransOffset = 2858;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_gainv_iz
	  section.data(280).logicalSrcIdx = 311;
	  section.data(280).dtTransOffset = 2859;
	
	  ;% controlAerobi_P.DiscreteTimeIntegrator_IC_a
	  section.data(281).logicalSrcIdx = 312;
	  section.data(281).dtTransOffset = 2860;
	
	  ;% controlAerobi_P.D_Yaw_rate_Value
	  section.data(282).logicalSrcIdx = 313;
	  section.data(282).dtTransOffset = 2861;
	
	  ;% controlAerobi_P.TSamp_WtEt_p
	  section.data(283).logicalSrcIdx = 314;
	  section.data(283).dtTransOffset = 2862;
	
	  ;% controlAerobi_P.Gain7_Gain
	  section.data(284).logicalSrcIdx = 315;
	  section.data(284).dtTransOffset = 2863;
	
	  ;% controlAerobi_P.scale2ticks_Gain
	  section.data(285).logicalSrcIdx = 316;
	  section.data(285).dtTransOffset = 2864;
	
	  ;% controlAerobi_P.Constant3_Value
	  section.data(286).logicalSrcIdx = 317;
	  section.data(286).dtTransOffset = 2865;
	
	  ;% controlAerobi_P.Gain_Gain_i2
	  section.data(287).logicalSrcIdx = 318;
	  section.data(287).dtTransOffset = 2866;
	
	  ;% controlAerobi_P.Gain1_Gain_mz
	  section.data(288).logicalSrcIdx = 319;
	  section.data(288).dtTransOffset = 2867;
	
	  ;% controlAerobi_P.Gain2_Gain_n
	  section.data(289).logicalSrcIdx = 320;
	  section.data(289).dtTransOffset = 2868;
	
	  ;% controlAerobi_P.DeadZone_Start_j
	  section.data(290).logicalSrcIdx = 321;
	  section.data(290).dtTransOffset = 2869;
	
	  ;% controlAerobi_P.DeadZone_End_c
	  section.data(291).logicalSrcIdx = 322;
	  section.data(291).dtTransOffset = 2870;
	
	  ;% controlAerobi_P.Gain_Gain_o
	  section.data(292).logicalSrcIdx = 323;
	  section.data(292).dtTransOffset = 2871;
	
	  ;% controlAerobi_P.DeadZone1_Start_o
	  section.data(293).logicalSrcIdx = 324;
	  section.data(293).dtTransOffset = 2872;
	
	  ;% controlAerobi_P.DeadZone1_End_n
	  section.data(294).logicalSrcIdx = 325;
	  section.data(294).dtTransOffset = 2873;
	
	  ;% controlAerobi_P.Gain1_Gain_au
	  section.data(295).logicalSrcIdx = 326;
	  section.data(295).dtTransOffset = 2874;
	
	  ;% controlAerobi_P.med_thrust_Value_n
	  section.data(296).logicalSrcIdx = 327;
	  section.data(296).dtTransOffset = 2875;
	
	  ;% controlAerobi_P.adapt_thrust_Gain_o
	  section.data(297).logicalSrcIdx = 328;
	  section.data(297).dtTransOffset = 2876;
	
	  ;% controlAerobi_P.uDLookupTable_tableData_j
	  section.data(298).logicalSrcIdx = 329;
	  section.data(298).dtTransOffset = 2877;
	
	  ;% controlAerobi_P.uDLookupTable_bp01Data_l
	  section.data(299).logicalSrcIdx = 330;
	  section.data(299).dtTransOffset = 3478;
	
	  ;% controlAerobi_P.dZgain_Gain_p
	  section.data(300).logicalSrcIdx = 331;
	  section.data(300).dtTransOffset = 4079;
	
	  ;% controlAerobi_P.DeadZone_Start_k
	  section.data(301).logicalSrcIdx = 332;
	  section.data(301).dtTransOffset = 4080;
	
	  ;% controlAerobi_P.DeadZone_End_l5
	  section.data(302).logicalSrcIdx = 333;
	  section.data(302).dtTransOffset = 4081;
	
	  ;% controlAerobi_P.Saturation_UpperSat_i
	  section.data(303).logicalSrcIdx = 334;
	  section.data(303).dtTransOffset = 4082;
	
	  ;% controlAerobi_P.Saturation_LowerSat_g
	  section.data(304).logicalSrcIdx = 335;
	  section.data(304).dtTransOffset = 4083;
	
	  ;% controlAerobi_P.Zgain_Gain
	  section.data(305).logicalSrcIdx = 336;
	  section.data(305).dtTransOffset = 4084;
	
	  ;% controlAerobi_P.I_RollPitch_rate_Value
	  section.data(306).logicalSrcIdx = 337;
	  section.data(306).dtTransOffset = 4085;
	
	  ;% controlAerobi_P.Constant_Value_gt
	  section.data(307).logicalSrcIdx = 338;
	  section.data(307).dtTransOffset = 4086;
	
	  ;% controlAerobi_P.Constant_Value_n
	  section.data(308).logicalSrcIdx = 339;
	  section.data(308).dtTransOffset = 4087;
	
	  ;% controlAerobi_P.Constant2_Value_p
	  section.data(309).logicalSrcIdx = 340;
	  section.data(309).dtTransOffset = 4088;
	
	  ;% controlAerobi_P.I_RollPitch_pos_Value
	  section.data(310).logicalSrcIdx = 341;
	  section.data(310).dtTransOffset = 4089;
	
	  ;% controlAerobi_P.Constant_Value_lb
	  section.data(311).logicalSrcIdx = 342;
	  section.data(311).dtTransOffset = 4090;
	
	  ;% controlAerobi_P.I_Yaw_pos_Value
	  section.data(312).logicalSrcIdx = 343;
	  section.data(312).dtTransOffset = 4091;
	
	  ;% controlAerobi_P.I_XY_pos_Value
	  section.data(313).logicalSrcIdx = 344;
	  section.data(313).dtTransOffset = 4092;
	
	  ;% controlAerobi_P.Constant_Value_jp
	  section.data(314).logicalSrcIdx = 345;
	  section.data(314).dtTransOffset = 4093;
	
	  ;% controlAerobi_P.I_XY_rate_Value
	  section.data(315).logicalSrcIdx = 346;
	  section.data(315).dtTransOffset = 4094;
	
	  ;% controlAerobi_P.Constant_Value_g3
	  section.data(316).logicalSrcIdx = 347;
	  section.data(316).dtTransOffset = 4095;
	
	  ;% controlAerobi_P.Zgain_Gain_e
	  section.data(317).logicalSrcIdx = 348;
	  section.data(317).dtTransOffset = 4096;
	
	  ;% controlAerobi_P.Constant_Value_gv
	  section.data(318).logicalSrcIdx = 349;
	  section.data(318).dtTransOffset = 4097;
	
	  ;% controlAerobi_P.I_Z_pos_Value
	  section.data(319).logicalSrcIdx = 350;
	  section.data(319).dtTransOffset = 4098;
	
	  ;% controlAerobi_P.I_Z_rate_Value
	  section.data(320).logicalSrcIdx = 351;
	  section.data(320).dtTransOffset = 4099;
	
	  ;% controlAerobi_P.Zgain_Gain_d
	  section.data(321).logicalSrcIdx = 352;
	  section.data(321).dtTransOffset = 4100;
	
	  ;% controlAerobi_P.Gain_Gain_f
	  section.data(322).logicalSrcIdx = 353;
	  section.data(322).dtTransOffset = 4101;
	
	  ;% controlAerobi_P.Gain1_Gain_i
	  section.data(323).logicalSrcIdx = 354;
	  section.data(323).dtTransOffset = 4102;
	
	  ;% controlAerobi_P.Gain2_Gain_m
	  section.data(324).logicalSrcIdx = 355;
	  section.data(324).dtTransOffset = 4103;
	
	  ;% controlAerobi_P.Gain3_Gain_n
	  section.data(325).logicalSrcIdx = 356;
	  section.data(325).dtTransOffset = 4104;
	
	  ;% controlAerobi_P.q_Value
	  section.data(326).logicalSrcIdx = 357;
	  section.data(326).dtTransOffset = 4105;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% controlAerobi_P.Gain3_Gain_o
	  section.data(1).logicalSrcIdx = 358;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_P.Gain2_Gain_o
	  section.data(2).logicalSrcIdx = 359;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controlAerobi_P.Constant5_Value_p
	  section.data(3).logicalSrcIdx = 360;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controlAerobi_P.Constant6_Value_i
	  section.data(4).logicalSrcIdx = 361;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controlAerobi_P.Constant7_Value_c
	  section.data(5).logicalSrcIdx = 362;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controlAerobi_P.Constant8_Value_d
	  section.data(6).logicalSrcIdx = 363;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controlAerobi_P.Constant9_Value
	  section.data(7).logicalSrcIdx = 364;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controlAerobi_P.Constant18_Value
	  section.data(8).logicalSrcIdx = 365;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controlAerobi_P.Constant10_Value
	  section.data(9).logicalSrcIdx = 366;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controlAerobi_P.Constant11_Value
	  section.data(10).logicalSrcIdx = 367;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controlAerobi_P.Constant12_Value
	  section.data(11).logicalSrcIdx = 368;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controlAerobi_P.Constant14_Value
	  section.data(12).logicalSrcIdx = 369;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controlAerobi_P.Constant4_Value_k
	  section.data(1).logicalSrcIdx = 370;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_P.Constant17_Value
	  section.data(2).logicalSrcIdx = 371;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controlAerobi_P.Constant16_Value
	  section.data(3).logicalSrcIdx = 372;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controlAerobi_P.Constant15_Value
	  section.data(4).logicalSrcIdx = 373;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controlAerobi_P.ManualSwitch2_CurrentSetting
	  section.data(1).logicalSrcIdx = 374;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_P.ManualSwitch13_CurrentSetting
	  section.data(2).logicalSrcIdx = 375;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controlAerobi_P.ManualSwitch14_CurrentSetting
	  section.data(3).logicalSrcIdx = 376;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controlAerobi_P.ManualSwitch15_CurrentSetting
	  section.data(4).logicalSrcIdx = 377;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% controlAerobi_P.enable_PC_Value
	  section.data(1).logicalSrcIdx = 378;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_P.rollPitch_pos_rate_Value
	  section.data(2).logicalSrcIdx = 379;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controlAerobi_P.position_Value
	  section.data(3).logicalSrcIdx = 380;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controlAerobi_P.geometricControl_Value
	  section.data(4).logicalSrcIdx = 381;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controlAerobi_P.Constant_Value_gs
	  section.data(5).logicalSrcIdx = 382;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controlAerobi_P.Z_pos_vel_Value
	  section.data(6).logicalSrcIdx = 383;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controlAerobi_P.XY_pos_vel_Value
	  section.data(7).logicalSrcIdx = 384;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controlAerobi_P.yaw_pos_rate_Value
	  section.data(8).logicalSrcIdx = 385;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 12;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (controlAerobi_B)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controlAerobi_B.Localpositionreceive_o1
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_B.ByteUnpack_o1_o
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% controlAerobi_B.MultiportSwitch
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_B.MultiportSwitch1
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 2;
	
	  ;% controlAerobi_B.MultiportSwitch2
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 4;
	
	  ;% controlAerobi_B.MultiportSwitch3
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 6;
	
	  ;% controlAerobi_B.Gain
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 8;
	
	  ;% controlAerobi_B.Gain1
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 11;
	
	  ;% controlAerobi_B.Gain2
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% controlAerobi_B.Gain3
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_B.vx
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controlAerobi_B.vy
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controlAerobi_B.ax
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controlAerobi_B.ay
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controlAerobi_B.PX4receive_o1
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_B.ByteUnpack_o1
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% controlAerobi_B._adc0
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_B._adc1
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controlAerobi_B._adc2
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controlAerobi_B._adc3
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controlAerobi_B._adc4
	  section.data(5).logicalSrcIdx = 22;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controlAerobi_B._adc5
	  section.data(6).logicalSrcIdx = 23;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controlAerobi_B.DataTypeConversion2
	  section.data(7).logicalSrcIdx = 24;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controlAerobi_B.DataTypeConversion
	  section.data(8).logicalSrcIdx = 25;
	  section.data(8).dtTransOffset = 45;
	
	  ;% controlAerobi_B.DataTypeConversion1
	  section.data(9).logicalSrcIdx = 26;
	  section.data(9).dtTransOffset = 62;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controlAerobi_B.ByteUnpack_o2
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_B.ByteUnpack_o2_f
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controlAerobi_B.BytePack
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_B.BytePack_j
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 44;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% controlAerobi_B.Compare
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_B.ALTHOLD
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controlAerobi_B.POS_HOLD
	  section.data(3).logicalSrcIdx = 35;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controlAerobi_B.sf_MATLABFunction_c.g_offset
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controlAerobi_B.sf_MATLABFunction_a.g_offset
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controlAerobi_B.sf_CreatedXYdesired.dXY_d
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controlAerobi_B.sf_CreatedXYdesired_o.dXY_d
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 12;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (controlAerobi_DWork)
    ;%
      section.nData     = 96;
      section.data(96)  = dumData; %prealloc
      
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_f
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% controlAerobi_DWork.Hlp_states
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_n
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 13;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_e
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 14;
	
	  ;% controlAerobi_DWork.UD_DSTATE
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 15;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n5
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 16;
	
	  ;% controlAerobi_DWork.UD_DSTATE_f
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 17;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 18;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_m
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 20;
	
	  ;% controlAerobi_DWork.UD_DSTATE_d
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 22;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_fo
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 24;
	
	  ;% controlAerobi_DWork.UD_DSTATE_o
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 26;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n2
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 28;
	
	  ;% controlAerobi_DWork.UD_DSTATE_oo
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 30;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_h
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 32;
	
	  ;% controlAerobi_DWork.UD_DSTATE_i
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 34;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_l
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 36;
	
	  ;% controlAerobi_DWork.UD_DSTATE_j
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 37;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_o
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 38;
	
	  ;% controlAerobi_DWork.UD_DSTATE_j5
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 39;
	
	  ;% controlAerobi_DWork.PX4receive_NetworkLib
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 40;
	
	  ;% controlAerobi_DWork.Unwrap_Prev
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 177;
	
	  ;% controlAerobi_DWork.Unwrap_Cumsum
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 178;
	
	  ;% controlAerobi_DWork.PrevY
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 179;
	
	  ;% controlAerobi_DWork.PrevY_i
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 182;
	
	  ;% controlAerobi_DWork.PrevY_m
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 185;
	
	  ;% controlAerobi_DWork.PrevY_f
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 188;
	
	  ;% controlAerobi_DWork.Localpositionreceive_NetworkLib
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 191;
	
	  ;% controlAerobi_DWork.PrevY_o
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 328;
	
	  ;% controlAerobi_DWork.PrevY_p
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 329;
	
	  ;% controlAerobi_DWork.PrevY_d
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 330;
	
	  ;% controlAerobi_DWork.PrevY_n
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 331;
	
	  ;% controlAerobi_DWork.x_k
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 332;
	
	  ;% controlAerobi_DWork.P_k
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 334;
	
	  ;% controlAerobi_DWork.buffer
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 338;
	
	  ;% controlAerobi_DWork.time
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 398;
	
	  ;% controlAerobi_DWork.index
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 399;
	
	  ;% controlAerobi_DWork.counter
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 400;
	
	  ;% controlAerobi_DWork.acc_
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 420;
	
	  ;% controlAerobi_DWork.x_k_a
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 423;
	
	  ;% controlAerobi_DWork.P_k_n
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 425;
	
	  ;% controlAerobi_DWork.time_a
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 429;
	
	  ;% controlAerobi_DWork.timeTS0
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 430;
	
	  ;% controlAerobi_DWork.dx_k
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 431;
	
	  ;% controlAerobi_DWork.dP_k
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 437;
	
	  ;% controlAerobi_DWork.index_j
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 473;
	
	  ;% controlAerobi_DWork.x_k_f
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 474;
	
	  ;% controlAerobi_DWork.P_k_h
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 480;
	
	  ;% controlAerobi_DWork.q_
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 516;
	
	  ;% controlAerobi_DWork.b_
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 520;
	
	  ;% controlAerobi_DWork.mi
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 523;
	
	  ;% controlAerobi_DWork.e3
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 526;
	
	  ;% controlAerobi_DWork.q__c
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 529;
	
	  ;% controlAerobi_DWork.b__h
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 533;
	
	  ;% controlAerobi_DWork.mi_g
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 536;
	
	  ;% controlAerobi_DWork.e3_k
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 539;
	
	  ;% controlAerobi_DWork.offset
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 542;
	
	  ;% controlAerobi_DWork.num
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 545;
	
	  ;% controlAerobi_DWork.state
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 546;
	
	  ;% controlAerobi_DWork.suma
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 547;
	
	  ;% controlAerobi_DWork.X_k
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 550;
	
	  ;% controlAerobi_DWork.P_k_hx
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 560;
	
	  ;% controlAerobi_DWork.t
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 660;
	
	  ;% controlAerobi_DWork.S_a
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 661;
	
	  ;% controlAerobi_DWork.S_q
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 691;
	
	  ;% controlAerobi_DWork.S_P
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 791;
	
	  ;% controlAerobi_DWork.time_n
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 1791;
	
	  ;% controlAerobi_DWork.q_est_aw_hat
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 1792;
	
	  ;% controlAerobi_DWork.time_l
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 1796;
	
	  ;% controlAerobi_DWork.z0
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 1797;
	
	  ;% controlAerobi_DWork.althold0
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 1798;
	
	  ;% controlAerobi_DWork.thrust0
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 1799;
	
	  ;% controlAerobi_DWork.posHold
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 1800;
	
	  ;% controlAerobi_DWork.posState
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 1802;
	
	  ;% controlAerobi_DWork.stop
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 1803;
	
	  ;% controlAerobi_DWork.XY_ref0
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 1805;
	
	  ;% controlAerobi_DWork.solution0
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 1807;
	
	  ;% controlAerobi_DWork.yaw_references
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 1808;
	
	  ;% controlAerobi_DWork.yaw_position_old
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 1809;
	
	  ;% controlAerobi_DWork.n
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 1810;
	
	  ;% controlAerobi_DWork.e_i
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 1811;
	
	  ;% controlAerobi_DWork.M
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 1814;
	
	  ;% controlAerobi_DWork.x_k_l
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 1817;
	
	  ;% controlAerobi_DWork.P_k_d
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 1823;
	
	  ;% controlAerobi_DWork.x_k_m
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 1859;
	
	  ;% controlAerobi_DWork.P_k_k
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 1865;
	
	  ;% controlAerobi_DWork.z0_g
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 1901;
	
	  ;% controlAerobi_DWork.althold0_b
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 1902;
	
	  ;% controlAerobi_DWork.thrust0_f
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 1903;
	
	  ;% controlAerobi_DWork.e_I
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 1904;
	
	  ;% controlAerobi_DWork.M_g
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 1907;
	
	  ;% controlAerobi_DWork.x_k_a1
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 1910;
	
	  ;% controlAerobi_DWork.P_k_c
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 1916;
	
	  ;% controlAerobi_DWork.x_k_fc
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 1952;
	
	  ;% controlAerobi_DWork.P_k_a
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 1958;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controlAerobi_DWork.PLOT_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 96;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_DWork.imu_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 97;
	  section.data(2).dtTransOffset = 4;
	
	  ;% controlAerobi_DWork.PX4_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 98;
	  section.data(3).dtTransOffset = 7;
	
	  ;% controlAerobi_DWork.datalog_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 99;
	  section.data(4).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_PrevRese
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_k
	  section.data(2).logicalSrcIdx = 101;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_b
	  section.data(3).logicalSrcIdx = 102;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_i
	  section.data(4).logicalSrcIdx = 103;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_c
	  section.data(5).logicalSrcIdx = 104;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_g
	  section.data(6).logicalSrcIdx = 105;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_l
	  section.data(7).logicalSrcIdx = 106;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_n
	  section.data(8).logicalSrcIdx = 107;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_p
	  section.data(9).logicalSrcIdx = 108;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_PrevR_gz
	  section.data(10).logicalSrcIdx = 109;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_PrevR_l3
	  section.data(11).logicalSrcIdx = 110;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controlAerobi_DWork.DiscreteTimeIntegrator_PrevR_cu
	  section.data(12).logicalSrcIdx = 111;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 74;
      section.data(74)  = dumData; %prealloc
      
	  ;% controlAerobi_DWork.Unwrap_FirstStep
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_DWork.x_k_not_empty
	  section.data(2).logicalSrcIdx = 113;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controlAerobi_DWork.P_k_not_empty
	  section.data(3).logicalSrcIdx = 114;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controlAerobi_DWork.buffer_not_empty
	  section.data(4).logicalSrcIdx = 115;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controlAerobi_DWork.time_not_empty
	  section.data(5).logicalSrcIdx = 116;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controlAerobi_DWork.index_not_empty
	  section.data(6).logicalSrcIdx = 117;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controlAerobi_DWork.counter_not_empty
	  section.data(7).logicalSrcIdx = 118;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controlAerobi_DWork.acc__not_empty
	  section.data(8).logicalSrcIdx = 119;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controlAerobi_DWork.x_k_not_empty_m
	  section.data(9).logicalSrcIdx = 120;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controlAerobi_DWork.P_k_not_empty_d
	  section.data(10).logicalSrcIdx = 121;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controlAerobi_DWork.time_not_empty_b
	  section.data(11).logicalSrcIdx = 122;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controlAerobi_DWork.timeTS0_not_empty
	  section.data(12).logicalSrcIdx = 123;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controlAerobi_DWork.dx_k_not_empty
	  section.data(13).logicalSrcIdx = 124;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controlAerobi_DWork.dP_k_not_empty
	  section.data(14).logicalSrcIdx = 125;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controlAerobi_DWork.queue_dx_not_empty
	  section.data(15).logicalSrcIdx = 126;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controlAerobi_DWork.queue_dP_not_empty
	  section.data(16).logicalSrcIdx = 127;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controlAerobi_DWork.index_not_empty_d
	  section.data(17).logicalSrcIdx = 128;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controlAerobi_DWork.Ndata_not_empty
	  section.data(18).logicalSrcIdx = 129;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controlAerobi_DWork.timefreq_not_empty
	  section.data(19).logicalSrcIdx = 130;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controlAerobi_DWork.x_k_not_empty_i
	  section.data(20).logicalSrcIdx = 131;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controlAerobi_DWork.P_k_not_empty_i
	  section.data(21).logicalSrcIdx = 132;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controlAerobi_DWork.x0_not_empty
	  section.data(22).logicalSrcIdx = 133;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controlAerobi_DWork.y0_not_empty
	  section.data(23).logicalSrcIdx = 134;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controlAerobi_DWork.z0_not_empty
	  section.data(24).logicalSrcIdx = 135;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controlAerobi_DWork.q__not_empty
	  section.data(25).logicalSrcIdx = 136;
	  section.data(25).dtTransOffset = 24;
	
	  ;% controlAerobi_DWork.b__not_empty
	  section.data(26).logicalSrcIdx = 137;
	  section.data(26).dtTransOffset = 25;
	
	  ;% controlAerobi_DWork.mi_not_empty
	  section.data(27).logicalSrcIdx = 138;
	  section.data(27).dtTransOffset = 26;
	
	  ;% controlAerobi_DWork.e3_not_empty
	  section.data(28).logicalSrcIdx = 139;
	  section.data(28).dtTransOffset = 27;
	
	  ;% controlAerobi_DWork.q__not_empty_h
	  section.data(29).logicalSrcIdx = 140;
	  section.data(29).dtTransOffset = 28;
	
	  ;% controlAerobi_DWork.b__not_empty_b
	  section.data(30).logicalSrcIdx = 141;
	  section.data(30).dtTransOffset = 29;
	
	  ;% controlAerobi_DWork.mi_not_empty_n
	  section.data(31).logicalSrcIdx = 142;
	  section.data(31).dtTransOffset = 30;
	
	  ;% controlAerobi_DWork.e3_not_empty_a
	  section.data(32).logicalSrcIdx = 143;
	  section.data(32).dtTransOffset = 31;
	
	  ;% controlAerobi_DWork.mb_not_empty
	  section.data(33).logicalSrcIdx = 144;
	  section.data(33).dtTransOffset = 32;
	
	  ;% controlAerobi_DWork.offset_not_empty
	  section.data(34).logicalSrcIdx = 145;
	  section.data(34).dtTransOffset = 33;
	
	  ;% controlAerobi_DWork.num_not_empty
	  section.data(35).logicalSrcIdx = 146;
	  section.data(35).dtTransOffset = 34;
	
	  ;% controlAerobi_DWork.state_not_empty
	  section.data(36).logicalSrcIdx = 147;
	  section.data(36).dtTransOffset = 35;
	
	  ;% controlAerobi_DWork.suma_not_empty
	  section.data(37).logicalSrcIdx = 148;
	  section.data(37).dtTransOffset = 36;
	
	  ;% controlAerobi_DWork.X_k_not_empty
	  section.data(38).logicalSrcIdx = 149;
	  section.data(38).dtTransOffset = 37;
	
	  ;% controlAerobi_DWork.P_k_not_empty_l
	  section.data(39).logicalSrcIdx = 150;
	  section.data(39).dtTransOffset = 38;
	
	  ;% controlAerobi_DWork.t_not_empty
	  section.data(40).logicalSrcIdx = 151;
	  section.data(40).dtTransOffset = 39;
	
	  ;% controlAerobi_DWork.S_a_not_empty
	  section.data(41).logicalSrcIdx = 152;
	  section.data(41).dtTransOffset = 40;
	
	  ;% controlAerobi_DWork.S_m_not_empty
	  section.data(42).logicalSrcIdx = 153;
	  section.data(42).dtTransOffset = 41;
	
	  ;% controlAerobi_DWork.S_g_not_empty
	  section.data(43).logicalSrcIdx = 154;
	  section.data(43).dtTransOffset = 42;
	
	  ;% controlAerobi_DWork.S_P_not_empty
	  section.data(44).logicalSrcIdx = 155;
	  section.data(44).dtTransOffset = 43;
	
	  ;% controlAerobi_DWork.time_not_empty_j
	  section.data(45).logicalSrcIdx = 156;
	  section.data(45).dtTransOffset = 44;
	
	  ;% controlAerobi_DWork.q_est_aw_hat_not_empty
	  section.data(46).logicalSrcIdx = 157;
	  section.data(46).dtTransOffset = 45;
	
	  ;% controlAerobi_DWork.q_est_amw_hat_not_empty
	  section.data(47).logicalSrcIdx = 158;
	  section.data(47).dtTransOffset = 46;
	
	  ;% controlAerobi_DWork.time_not_empty_l
	  section.data(48).logicalSrcIdx = 159;
	  section.data(48).dtTransOffset = 47;
	
	  ;% controlAerobi_DWork.z0_not_empty_c
	  section.data(49).logicalSrcIdx = 160;
	  section.data(49).dtTransOffset = 48;
	
	  ;% controlAerobi_DWork.althold0_not_empty
	  section.data(50).logicalSrcIdx = 161;
	  section.data(50).dtTransOffset = 49;
	
	  ;% controlAerobi_DWork.thrust0_not_empty
	  section.data(51).logicalSrcIdx = 162;
	  section.data(51).dtTransOffset = 50;
	
	  ;% controlAerobi_DWork.posHold_not_empty
	  section.data(52).logicalSrcIdx = 163;
	  section.data(52).dtTransOffset = 51;
	
	  ;% controlAerobi_DWork.posState_not_empty
	  section.data(53).logicalSrcIdx = 164;
	  section.data(53).dtTransOffset = 52;
	
	  ;% controlAerobi_DWork.stop_not_empty
	  section.data(54).logicalSrcIdx = 165;
	  section.data(54).dtTransOffset = 53;
	
	  ;% controlAerobi_DWork.XY_ref0_not_empty
	  section.data(55).logicalSrcIdx = 166;
	  section.data(55).dtTransOffset = 54;
	
	  ;% controlAerobi_DWork.solution0_not_empty
	  section.data(56).logicalSrcIdx = 167;
	  section.data(56).dtTransOffset = 55;
	
	  ;% controlAerobi_DWork.yaw_references_not_empty
	  section.data(57).logicalSrcIdx = 168;
	  section.data(57).dtTransOffset = 56;
	
	  ;% controlAerobi_DWork.yaw_position_old_not_empty
	  section.data(58).logicalSrcIdx = 169;
	  section.data(58).dtTransOffset = 57;
	
	  ;% controlAerobi_DWork.n_not_empty
	  section.data(59).logicalSrcIdx = 170;
	  section.data(59).dtTransOffset = 58;
	
	  ;% controlAerobi_DWork.e_i_not_empty
	  section.data(60).logicalSrcIdx = 171;
	  section.data(60).dtTransOffset = 59;
	
	  ;% controlAerobi_DWork.M_not_empty
	  section.data(61).logicalSrcIdx = 172;
	  section.data(61).dtTransOffset = 60;
	
	  ;% controlAerobi_DWork.x_k_not_empty_a
	  section.data(62).logicalSrcIdx = 173;
	  section.data(62).dtTransOffset = 61;
	
	  ;% controlAerobi_DWork.P_k_not_empty_lk
	  section.data(63).logicalSrcIdx = 174;
	  section.data(63).dtTransOffset = 62;
	
	  ;% controlAerobi_DWork.x_k_not_empty_d
	  section.data(64).logicalSrcIdx = 175;
	  section.data(64).dtTransOffset = 63;
	
	  ;% controlAerobi_DWork.P_k_not_empty_o
	  section.data(65).logicalSrcIdx = 176;
	  section.data(65).dtTransOffset = 64;
	
	  ;% controlAerobi_DWork.z0_not_empty_h
	  section.data(66).logicalSrcIdx = 177;
	  section.data(66).dtTransOffset = 65;
	
	  ;% controlAerobi_DWork.althold0_not_empty_k
	  section.data(67).logicalSrcIdx = 178;
	  section.data(67).dtTransOffset = 66;
	
	  ;% controlAerobi_DWork.thrust0_not_empty_h
	  section.data(68).logicalSrcIdx = 179;
	  section.data(68).dtTransOffset = 67;
	
	  ;% controlAerobi_DWork.e_I_not_empty
	  section.data(69).logicalSrcIdx = 180;
	  section.data(69).dtTransOffset = 68;
	
	  ;% controlAerobi_DWork.M_not_empty_f
	  section.data(70).logicalSrcIdx = 181;
	  section.data(70).dtTransOffset = 69;
	
	  ;% controlAerobi_DWork.x_k_not_empty_mk
	  section.data(71).logicalSrcIdx = 182;
	  section.data(71).dtTransOffset = 70;
	
	  ;% controlAerobi_DWork.P_k_not_empty_f
	  section.data(72).logicalSrcIdx = 183;
	  section.data(72).dtTransOffset = 71;
	
	  ;% controlAerobi_DWork.x_k_not_empty_my
	  section.data(73).logicalSrcIdx = 184;
	  section.data(73).dtTransOffset = 72;
	
	  ;% controlAerobi_DWork.P_k_not_empty_ol
	  section.data(74).logicalSrcIdx = 185;
	  section.data(74).dtTransOffset = 73;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% controlAerobi_DWork.sf_MATLABFunction_c.offset
	  section.data(1).logicalSrcIdx = 186;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_DWork.sf_MATLABFunction_c.num
	  section.data(2).logicalSrcIdx = 187;
	  section.data(2).dtTransOffset = 3;
	
	  ;% controlAerobi_DWork.sf_MATLABFunction_c.suma
	  section.data(3).logicalSrcIdx = 188;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% controlAerobi_DWork.sf_MATLABFunction_c.offset_not_empty
	  section.data(1).logicalSrcIdx = 189;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_DWork.sf_MATLABFunction_c.num_not_empty
	  section.data(2).logicalSrcIdx = 190;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controlAerobi_DWork.sf_MATLABFunction_c.suma_not_empty
	  section.data(3).logicalSrcIdx = 191;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% controlAerobi_DWork.sf_MATLABFunction_a.offset
	  section.data(1).logicalSrcIdx = 192;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_DWork.sf_MATLABFunction_a.num
	  section.data(2).logicalSrcIdx = 193;
	  section.data(2).dtTransOffset = 3;
	
	  ;% controlAerobi_DWork.sf_MATLABFunction_a.suma
	  section.data(3).logicalSrcIdx = 194;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% controlAerobi_DWork.sf_MATLABFunction_a.offset_not_empty
	  section.data(1).logicalSrcIdx = 195;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controlAerobi_DWork.sf_MATLABFunction_a.num_not_empty
	  section.data(2).logicalSrcIdx = 196;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controlAerobi_DWork.sf_MATLABFunction_a.suma_not_empty
	  section.data(3).logicalSrcIdx = 197;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 569576501;
  targMap.checksum1 = 3272881783;
  targMap.checksum2 = 1823612586;
  targMap.checksum3 = 1467950775;

