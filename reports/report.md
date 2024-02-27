# BeamProp report

81 layouts, 46479100 cell-steps, 586 checks: 586 PASS, 0 FAIL.

Every layout is a text file in `cases/`. Its expectations come from an independent propagation or from a closed form, stated in the comments at the top of the file.
Per-layout results are in `reports/cases/`, intensity maps in `reports/figures/cases/`.

## Families

| family | layouts | checks | passed |
|---|---|---|---|
| absorbing edges | 6 | 25 | 25 |
| directional couplers | 9 | 70 | 70 |
| free propagation | 8 | 53 | 53 |
| step and grid | 8 | 29 | 29 |
| launch conditions | 7 | 42 | 42 |
| multimode interferometers | 14 | 100 | 100 |
| s-bends | 7 | 35 | 35 |
| straight guides | 10 | 70 | 70 |
| tapers | 8 | 40 | 40 |
| y-branches | 4 | 28 | 28 |

## Agreement with the independent propagation

Each layout is read and stepped again by `reference.py` (NumPy, banded solver). Powers are fractions of the launched power, lengths in micrometres, the field relative to its peak.

| quantity | largest difference over the library |
|---|---|
| power | 5.02e-11 |
| total | 4.79e-11 |
| centroid | 4.49e-09 |
| radius | 4.96e-09 |
| n_track | 4.96e-11 |
| field | 4.22e-11 |

## Studies

### Step size (coupler, against the solution that needs no stepping)

Fitted order: 1.97.

| step, um | error of the output field |
|---|---|
| 0.062500 | 1.08e-03 |
| 0.125000 | 3.83e-03 |
| 0.250000 | 0.015941 |
| 0.500000 | 0.063628 |
| 1.000000 | 0.246095 |

### Taper 0.5 to 3 um: transmission against length

| length, um | transmission |
|---|---|
| 5 | 0.93142 |
| 10 | 0.97611 |
| 20 | 0.99100 |
| 40 | 0.99766 |
| 80 | 0.99952 |

### Taper 3 to 0.5 um: transmission against length

| length, um | transmission |
|---|---|
| 10 | 0.97611 |
| 40 | 0.99766 |
| 80 | 0.99952 |

### S-bend, 1 um offset: transmission against length

| length, um | transmission |
|---|---|
| 10 | 0.99806 |
| 20 | 0.99994 |
| 40 | 0.99994 |

### S-bend, 2 um offset: transmission against length

| length, um | transmission |
|---|---|
| 20 | 0.99966 |
| 40 | 0.99987 |
| 80 | 0.99989 |

### Directional couplers

| gap, nm | n_even - n_odd | coupling length, um | launch guide empty at, um |
|---|---|---|---|
| 100 | 0.0925 | 8.3649 | 8.5000 |
| 150 | 0.0593 | 13.0543 | 13.0000 |
| 200 | 0.0380 | 20.3694 | 20.5000 |
| 250 | 0.0244 | 31.7343 | 31.7500 |
| 300 | 0.0157 | 49.4696 | 49.5000 |

### 1x2 multimode interferometers: power per output against length

| length over the imaging length | 4 um wide | 6 um wide | 8 um wide |
|---|---|---|---|
| 0.8000 | n/a | 0.1842 | n/a |
| 0.9000 | 0.4230 | 0.3015 | 0.1989 |
| 1.0000 | 0.4930 | 0.4922 | 0.4902 |
| 1.1000 | 0.4422 | 0.3085 | 0.1931 |
| 1.2000 | n/a | 0.1833 | n/a |

### Absorbing edges: a beam at 15 degrees leaving the window

| absorber width, um | strength | power left in the window |
|---|---|---|
| 2.00000 | 0.30000 | 0.01409 |
| 5.00000 | 0.00000 | 1.00000 |
| 5.00000 | 0.03000 | 0.33991 |
| 5.00000 | 0.30000 | 4.88e-04 |
| 5.00000 | 3.00000 | 0.03128 |
| 10.00000 | 0.30000 | 2.79e-04 |

## All layouts

| layout | cells | steps | power left | strongest monitor | its power | checks | passed |
|---|---|---|---|---|---|---|---|
| absorber_s000 | 800 | 600 | 1.0000 |  | n/a | 5 | 5 |
| absorber_s003 | 800 | 600 | 0.3399 |  | n/a | 4 | 4 |
| absorber_s030 | 800 | 600 | 4.88e-04 |  | n/a | 4 | 4 |
| absorber_s300 | 800 | 600 | 0.0313 |  | n/a | 4 | 4 |
| absorber_wide10 | 1,000 | 600 | 2.79e-04 |  | n/a | 4 | 4 |
| absorber_wide2 | 680 | 600 | 0.0141 |  | n/a | 4 | 4 |
| coupler_gap100 | 700 | 75 | 0.9999 | cross_full | 0.9944 | 10 | 10 |
| coupler_gap150 | 700 | 112 | 0.9999 | cross_full | 0.9929 | 10 | 10 |
| coupler_gap200 | 700 | 171 | 1.0000 | cross_full | 0.9978 | 10 | 10 |
| coupler_gap250 | 700 | 262 | 1.0000 | cross_full | 0.9993 | 10 | 10 |
| coupler_gap300 | 700 | 404 | 1.0000 | cross_full | 1.0000 | 10 | 10 |
| coupler_length025 | 700 | 20 | 1.0000 | bar | 0.8576 | 5 | 5 |
| coupler_length050 | 700 | 41 | 1.0000 | cross | 0.5058 | 5 | 5 |
| coupler_length075 | 700 | 61 | 1.0000 | cross | 0.8499 | 5 | 5 |
| coupler_length150 | 700 | 122 | 1.0000 | cross | 0.5050 | 5 | 5 |
| free_tilt02 | 1,600 | 800 | 1.0000 |  | n/a | 6 | 6 |
| free_tilt05 | 1,600 | 800 | 1.0000 |  | n/a | 6 | 6 |
| free_tilt10 | 1,600 | 800 | 0.9999 |  | n/a | 6 | 6 |
| free_w10 | 9,840 | 480 | 1.0000 |  | n/a | 7 | 7 |
| free_w15 | 5,480 | 400 | 1.0000 |  | n/a | 7 | 7 |
| free_w20 | 6,160 | 600 | 1.0000 |  | n/a | 7 | 7 |
| free_w30 | 5,520 | 800 | 1.0000 |  | n/a | 7 | 7 |
| free_w50 | 5,080 | 1,200 | 1.0000 |  | n/a | 7 | 7 |
| grid_dx125 | 1,120 | 80 | 1.0000 | cross | 0.9976 | 3 | 3 |
| grid_dx250 | 560 | 80 | 1.0000 | cross | 0.9978 | 3 | 3 |
| grid_dx500 | 280 | 80 | 1.0000 | cross | 0.9985 | 3 | 3 |
| launch_offset100 | 1,200 | 800 | 0.9891 | out | 0.8738 | 6 | 6 |
| launch_offset200 | 1,200 | 800 | 0.9012 | out | 0.5864 | 6 | 6 |
| launch_offset300 | 1,200 | 800 | 0.6832 | out | 0.3038 | 6 | 6 |
| launch_w400_into_w500 | 1,200 | 800 | 0.9939 | out | 0.9934 | 6 | 6 |
| launch_w500_into_w1200 | 1,200 | 800 | 0.9865 | out | 0.8108 | 6 | 6 |
| launch_w500_into_w800 | 1,200 | 800 | 0.9955 | out | 0.9474 | 6 | 6 |
| launch_w800_into_w500 | 1,200 | 800 | 0.9510 | out | 0.9474 | 6 | 6 |
| mmi_1x2_w4_l090 | 700 | 157 | 0.9963 | upper | 0.4230 | 7 | 7 |
| mmi_1x2_w4_l100 | 700 | 164 | 0.9997 | upper | 0.4930 | 8 | 8 |
| mmi_1x2_w4_l110 | 700 | 170 | 0.9954 | upper | 0.4422 | 7 | 7 |
| mmi_1x2_w6_l080 | 800 | 211 | 0.9969 | upper | 0.1842 | 7 | 7 |
| mmi_1x2_w6_l090 | 800 | 225 | 0.9977 | upper | 0.3015 | 7 | 7 |
| mmi_1x2_w6_l100 | 800 | 239 | 0.9996 | upper | 0.4922 | 8 | 8 |
| mmi_1x2_w6_l110 | 800 | 253 | 0.9930 | upper | 0.3085 | 7 | 7 |
| mmi_1x2_w6_l120 | 800 | 267 | 0.9977 | upper | 0.1833 | 7 | 7 |
| mmi_1x2_w8_l090 | 900 | 319 | 0.9965 | upper | 0.1989 | 7 | 7 |
| mmi_1x2_w8_l100 | 900 | 343 | 0.9995 | upper | 0.4902 | 8 | 8 |
| mmi_1x2_w8_l110 | 900 | 368 | 0.9966 | upper | 0.1931 | 7 | 7 |
| mmi_2x2_l090 | 800 | 267 | 0.9978 | cross | 0.2929 | 6 | 6 |
| mmi_2x2_l100 | 800 | 285 | 0.9994 | bar | 0.4913 | 8 | 8 |
| mmi_2x2_l110 | 800 | 304 | 0.9970 | bar | 0.2838 | 6 | 6 |
| sbend_off1_l10 | 1,200 | 120 | 1.0000 | out | 0.9981 | 5 | 5 |
| sbend_off1_l20 | 1,200 | 160 | 1.0000 | out | 0.9999 | 5 | 5 |
| sbend_off1_l40 | 1,200 | 240 | 1.0000 | out | 0.9999 | 5 | 5 |
| sbend_off2_l20 | 1,200 | 160 | 1.0000 | out | 0.9997 | 5 | 5 |
| sbend_off2_l40 | 1,200 | 240 | 1.0000 | out | 0.9999 | 5 | 5 |
| sbend_off2_l80 | 1,200 | 400 | 1.0000 | out | 0.9999 | 5 | 5 |
| sbend_off4_l80 | 1,200 | 400 | 1.0000 | out | 0.9998 | 5 | 5 |
| step_dz00625 | 600 | 320 | 1.0000 | out | 1.0000 | 4 | 4 |
| step_dz01250 | 600 | 160 | 1.0000 | out | 1.0000 | 4 | 4 |
| step_dz02500 | 600 | 80 | 1.0000 | out | 1.0000 | 4 | 4 |
| step_dz05000 | 600 | 40 | 1.0000 | out | 1.0000 | 4 | 4 |
| step_dz10000 | 600 | 20 | 1.0000 | out | 1.0000 | 4 | 4 |
| straight_ref1444 | 600 | 400 | 1.0000 | out | 1.0000 | 7 | 7 |
| straight_ref2000 | 600 | 400 | 1.0000 | out | 1.0000 | 7 | 7 |
| straight_ref3200 | 600 | 400 | 1.0000 | out | 1.0000 | 7 | 7 |
| straight_w0400_m0 | 600 | 400 | 1.0000 | out | 1.0000 | 7 | 7 |
| straight_w0500_m0 | 600 | 400 | 1.0000 | out | 1.0000 | 7 | 7 |
| straight_w0800_m0 | 600 | 400 | 1.0000 | out | 1.0000 | 7 | 7 |
| straight_w1200_m0 | 600 | 400 | 1.0000 | out | 1.0000 | 7 | 7 |
| straight_w1200_m1 | 600 | 400 | 1.0000 | out | 1.0000 | 7 | 7 |
| straight_w2000_m1 | 600 | 400 | 1.0000 | out | 1.0000 | 7 | 7 |
| straight_w2000_m2 | 600 | 400 | 1.0000 | out | 1.0000 | 7 | 7 |
| taper_down_l10 | 1,000 | 120 | 1.0000 | out | 0.9761 | 5 | 5 |
| taper_down_l40 | 1,000 | 240 | 1.0000 | out | 0.9977 | 5 | 5 |
| taper_down_l80 | 1,000 | 400 | 1.0000 | out | 0.9995 | 5 | 5 |
| taper_up_l05 | 1,000 | 100 | 1.0000 | out | 0.9314 | 5 | 5 |
| taper_up_l10 | 1,000 | 120 | 1.0000 | out | 0.9761 | 5 | 5 |
| taper_up_l20 | 1,000 | 160 | 1.0000 | out | 0.9910 | 5 | 5 |
| taper_up_l40 | 1,000 | 240 | 1.0000 | out | 0.9977 | 5 | 5 |
| taper_up_l80 | 1,000 | 400 | 1.0000 | out | 0.9995 | 5 | 5 |
| ybranch_l10 | 1,200 | 160 | 1.0000 | upper | 0.4953 | 7 | 7 |
| ybranch_l20 | 1,200 | 200 | 1.0000 | upper | 0.4997 | 7 | 7 |
| ybranch_l40 | 1,200 | 280 | 1.0000 | upper | 0.4999 | 7 | 7 |
| ybranch_l80 | 1,200 | 440 | 0.9999 | upper | 0.4998 | 7 | 7 |
