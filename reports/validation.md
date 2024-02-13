# Validation checks

| area | check | status | detail |
|---|---|---|---|
| independent propagation | absorber_s000: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.4e-11 of its peak |
| absorbing edges | absorber_s000: total end 1.000000000 2e-7 | PASS | 1.00000000, expected 1.00000000, off by -5.74e-13 |
| absorbing edges | absorber_s000: centroid end 1.2921579 2e-6 | PASS | 1.29215788, expected 1.29215790, off by -1.58e-08 |
| absorbing edges | absorber_s000: radius end 11.3348111 2e-6 | PASS | 11.33481113, expected 11.33481110, off by 2.94e-08 |
| absorbing edges | absorber_s000: neff 1.417939477 2e-8 | PASS | 1.41793948, expected 1.41793948, off by -5.64e-11 |
| absorbing edges | absorber_s000: conserved 1e-9 | PASS | largest change of the total power 5.74e-13 over 600 steps of 0.250 um |
| independent propagation | absorber_s003: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.8e-11 of its peak |
| absorbing edges | absorber_s003: total end 0.339907081 2e-7 | PASS | 0.33990708, expected 0.33990708, off by -1.10e-10 |
| absorbing edges | absorber_s003: centroid end 0.6054151 2e-6 | PASS | 0.60541506, expected 0.60541510, off by -4.42e-08 |
| absorbing edges | absorber_s003: radius end 11.2690940 2e-6 | PASS | 11.26909402, expected 11.26909400, off by 1.97e-08 |
| absorbing edges | absorber_s003: neff 1.417948075 2e-8 | PASS | 1.41794807, expected 1.41794807, off by -2.17e-10 |
| independent propagation | absorber_s030: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 1.0e-11 of its peak |
| absorbing edges | absorber_s030: total end 0.000488212 2e-7 | PASS | 0.00048821, expected 0.00048821, off by -1.43e-10 |
| absorbing edges | absorber_s030: centroid end 6.0734513 2e-6 | PASS | 6.07345125, expected 6.07345130, off by -4.92e-08 |
| absorbing edges | absorber_s030: radius end 16.8998764 2e-6 | PASS | 16.89987644, expected 16.89987640, off by 3.88e-08 |
| absorbing edges | absorber_s030: neff 1.417935639 2e-8 | PASS | 1.41793564, expected 1.41793564, off by -3.45e-10 |
| independent propagation | absorber_s300: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 1.4e-11 of its peak |
| absorbing edges | absorber_s300: total end 0.031279017 2e-7 | PASS | 0.03127902, expected 0.03127902, off by 4.84e-10 |
| absorbing edges | absorber_s300: centroid end -2.8305508 2e-6 | PASS | -2.83055084, expected -2.83055080, off by -3.98e-08 |
| absorbing edges | absorber_s300: radius end 10.7930516 2e-6 | PASS | 10.79305157, expected 10.79305160, off by -3.13e-08 |
| absorbing edges | absorber_s300: neff 1.417220298 2e-8 | PASS | 1.41722030, expected 1.41722030, off by 3.24e-10 |
| independent propagation | absorber_wide10: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 8.1e-12 of its peak |
| absorbing edges | absorber_wide10: total end 0.000278833 2e-7 | PASS | 0.00027883, expected 0.00027883, off by -1.25e-10 |
| absorbing edges | absorber_wide10: centroid end 17.8027847 2e-6 | PASS | 17.80278467, expected 17.80278470, off by -2.63e-08 |
| absorbing edges | absorber_wide10: radius end 5.5662135 2e-6 | PASS | 5.56621350, expected 5.56621350, off by 2.29e-09 |
| absorbing edges | absorber_wide10: neff 1.417950495 2e-8 | PASS | 1.41795049, expected 1.41795049, off by -3.73e-10 |
| independent propagation | absorber_wide2: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.2e-11 of its peak |
| absorbing edges | absorber_wide2: total end 0.014094841 2e-7 | PASS | 0.01409484, expected 0.01409484, off by -3.39e-10 |
| absorbing edges | absorber_wide2: centroid end -1.5776130 2e-6 | PASS | -1.57761298, expected -1.57761300, off by 2.32e-08 |
| absorbing edges | absorber_wide2: radius end 12.7241369 2e-6 | PASS | 12.72413686, expected 12.72413690, off by -4.12e-08 |
| absorbing edges | absorber_wide2: neff 1.417072478 2e-8 | PASS | 1.41707248, expected 1.41707248, off by 1.86e-10 |
| independent propagation | coupler_gap100: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.9e-11 of its peak |
| directional couplers | coupler_gap100: power half_cross 0.509489396 2e-7 | PASS | 0.50948940, expected 0.50948940, off by 3.83e-10 |
| directional couplers | coupler_gap100: power cross_full 0.994402871 2e-7 | PASS | 0.99440287, expected 0.99440287, off by -6.23e-11 |
| directional couplers | coupler_gap100: power bar_full 0.011591783 2e-7 | PASS | 0.01159178, expected 0.01159178, off by -3.51e-10 |
| directional couplers | coupler_gap100: power bar_end 0.848719694 2e-7 | PASS | 0.84871969, expected 0.84871969, off by -1.44e-11 |
| directional couplers | coupler_gap100: power cross_end 0.146094149 2e-7 | PASS | 0.14609415, expected 0.14609415, off by -3.35e-10 |
| directional couplers | coupler_gap100: neff 2.675559859 2e-8 | PASS | 2.67555986, expected 2.67555986, off by 4.74e-10 |
| directional couplers | coupler_gap100: power_above cross_full 0.99 | PASS | 0.994403 against the bound 0.990000 (margin 4.40e-03) |
| directional couplers | coupler_gap100: power_below bar_full 0.015 | PASS | 0.011592 against the bound 0.015000 (margin -3.41e-03) |
| directional couplers | coupler_gap100: power half_cross 0.5 0.02 | PASS | 0.50948940, expected 0.50000000, off by 9.49e-03 |
| directional couplers | coupler_gap100: sum bar_end cross_end 1.0 0.01 | PASS | 0.99481384, expected 1.00000000, off by -5.19e-03 |
| independent propagation | coupler_gap150: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.1e-11 of its peak |
| directional couplers | coupler_gap150: power half_cross 0.495465978 2e-7 | PASS | 0.49546598, expected 0.49546598, off by 3.95e-10 |
| directional couplers | coupler_gap150: power cross_full 0.992922740 2e-7 | PASS | 0.99292274, expected 0.99292274, off by -5.64e-11 |
| directional couplers | coupler_gap150: power bar_full 0.005341318 2e-7 | PASS | 0.00534132, expected 0.00534132, off by -2.60e-12 |
| directional couplers | coupler_gap150: power bar_end 0.948128252 2e-7 | PASS | 0.94812825, expected 0.94812825, off by 4.75e-10 |
| directional couplers | coupler_gap150: power cross_end 0.056440567 2e-7 | PASS | 0.05644057, expected 0.05644057, off by -1.73e-10 |
| directional couplers | coupler_gap150: neff 2.658815502 2e-8 | PASS | 2.65881550, expected 2.65881550, off by 1.03e-10 |
| directional couplers | coupler_gap150: power_above cross_full 0.99 | PASS | 0.992923 against the bound 0.990000 (margin 2.92e-03) |
| directional couplers | coupler_gap150: power_below bar_full 0.015 | PASS | 0.005341 against the bound 0.015000 (margin -9.66e-03) |
| directional couplers | coupler_gap150: power half_cross 0.5 0.02 | PASS | 0.49546598, expected 0.50000000, off by -4.53e-03 |
| directional couplers | coupler_gap150: sum bar_end cross_end 1.0 0.01 | PASS | 1.00456882, expected 1.00000000, off by 4.57e-03 |
| independent propagation | coupler_gap200: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.0e-11 of its peak |
| directional couplers | coupler_gap200: power half_cross 0.505797145 2e-7 | PASS | 0.50579714, expected 0.50579714, off by -3.12e-10 |
| directional couplers | coupler_gap200: power cross_full 0.997809020 2e-7 | PASS | 0.99780902, expected 0.99780902, off by 1.38e-10 |
| directional couplers | coupler_gap200: power bar_full 0.002812010 2e-7 | PASS | 0.00281201, expected 0.00281201, off by -4.12e-10 |
| directional couplers | coupler_gap200: power bar_end 0.975487005 2e-7 | PASS | 0.97548700, expected 0.97548700, off by -1.01e-10 |
| directional couplers | coupler_gap200: power cross_end 0.026250017 2e-7 | PASS | 0.02625002, expected 0.02625002, off by 4.46e-10 |
| directional couplers | coupler_gap200: neff 2.648884804 2e-8 | PASS | 2.64888480, expected 2.64888480, off by -4.65e-10 |
| directional couplers | coupler_gap200: power_above cross_full 0.995 | PASS | 0.997809 against the bound 0.995000 (margin 2.81e-03) |
| directional couplers | coupler_gap200: power_below bar_full 0.005 | PASS | 0.002812 against the bound 0.005000 (margin -2.19e-03) |
| directional couplers | coupler_gap200: power half_cross 0.5 0.02 | PASS | 0.50579714, expected 0.50000000, off by 5.80e-03 |
| directional couplers | coupler_gap200: sum bar_end cross_end 1.0 0.002 | PASS | 1.00173702, expected 1.00000000, off by 1.74e-03 |
| independent propagation | coupler_gap250: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.9e-11 of its peak |
| directional couplers | coupler_gap250: power half_cross 0.494454978 2e-7 | PASS | 0.49445498, expected 0.49445498, off by 3.13e-11 |
| directional couplers | coupler_gap250: power cross_full 0.999280960 2e-7 | PASS | 0.99928096, expected 0.99928096, off by -2.06e-10 |
| directional couplers | coupler_gap250: power bar_full 0.001285102 2e-7 | PASS | 0.00128510, expected 0.00128510, off by 2.11e-11 |
| directional couplers | coupler_gap250: power bar_end 0.989075573 2e-7 | PASS | 0.98907557, expected 0.98907557, off by 1.22e-10 |
| directional couplers | coupler_gap250: power cross_end 0.011318392 2e-7 | PASS | 0.01131839, expected 0.01131839, off by -3.50e-10 |
| directional couplers | coupler_gap250: neff 2.641330622 2e-8 | PASS | 2.64133062, expected 2.64133062, off by 9.17e-11 |
| directional couplers | coupler_gap250: power_above cross_full 0.995 | PASS | 0.999281 against the bound 0.995000 (margin 4.28e-03) |
| directional couplers | coupler_gap250: power_below bar_full 0.005 | PASS | 0.001285 against the bound 0.005000 (margin -3.71e-03) |
| directional couplers | coupler_gap250: power half_cross 0.5 0.02 | PASS | 0.49445498, expected 0.50000000, off by -5.55e-03 |
| directional couplers | coupler_gap250: sum bar_end cross_end 1.0 0.002 | PASS | 1.00039396, expected 1.00000000, off by 3.94e-04 |
| independent propagation | coupler_gap300: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.9e-11 of its peak |
| directional couplers | coupler_gap300: power half_cross 0.500787658 2e-7 | PASS | 0.50078766, expected 0.50078766, off by -1.08e-10 |
| directional couplers | coupler_gap300: power cross_full 0.999951233 2e-7 | PASS | 0.99995123, expected 0.99995123, off by -3.66e-10 |
| directional couplers | coupler_gap300: power bar_full 0.000628536 2e-7 | PASS | 0.00062854, expected 0.00062854, off by 1.11e-12 |
| directional couplers | coupler_gap300: power bar_end 0.995256589 2e-7 | PASS | 0.99525659, expected 0.99525659, off by -6.58e-11 |
| directional couplers | coupler_gap300: power cross_end 0.004892626 2e-7 | PASS | 0.00489263, expected 0.00489263, off by -6.82e-11 |
| directional couplers | coupler_gap300: neff 2.636740334 2e-8 | PASS | 2.63674033, expected 2.63674033, off by -3.35e-11 |
| directional couplers | coupler_gap300: power_above cross_full 0.995 | PASS | 0.999951 against the bound 0.995000 (margin 4.95e-03) |
| directional couplers | coupler_gap300: power_below bar_full 0.005 | PASS | 0.000629 against the bound 0.005000 (margin -4.37e-03) |
| directional couplers | coupler_gap300: power half_cross 0.5 0.02 | PASS | 0.50078766, expected 0.50000000, off by 7.88e-04 |
| directional couplers | coupler_gap300: sum bar_end cross_end 1.0 0.002 | PASS | 1.00014921, expected 1.00000000, off by 1.49e-04 |
| independent propagation | coupler_length025: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.2e-11 of its peak |
| directional couplers | coupler_length025: power bar 0.857645443 2e-7 | PASS | 0.85764544, expected 0.85764544, off by -4.54e-10 |
| directional couplers | coupler_length025: power cross 0.144022471 2e-7 | PASS | 0.14402247, expected 0.14402247, off by 1.16e-10 |
| directional couplers | coupler_length025: neff 2.631756959 2e-8 | PASS | 2.63175696, expected 2.63175696, off by -4.46e-10 |
| directional couplers | coupler_length025: power cross 0.14645 0.02 | PASS | 0.14402247, expected 0.14645000, off by -2.43e-03 |
| directional couplers | coupler_length025: sum bar cross 1.0 2e-3 | PASS | 1.00166791, expected 1.00000000, off by 1.67e-03 |
| independent propagation | coupler_length050: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 4.1e-11 of its peak |
| directional couplers | coupler_length050: power bar 0.494418305 2e-7 | PASS | 0.49441831, expected 0.49441831, off by 6.25e-11 |
| directional couplers | coupler_length050: power cross 0.505797145 2e-7 | PASS | 0.50579714, expected 0.50579714, off by -3.12e-10 |
| directional couplers | coupler_length050: neff 2.631966430 2e-8 | PASS | 2.63196643, expected 2.63196643, off by 1.40e-10 |
| directional couplers | coupler_length050: power cross 0.50000 0.02 | PASS | 0.50579714, expected 0.50000000, off by 5.80e-03 |
| directional couplers | coupler_length050: sum bar cross 1.0 2e-3 | PASS | 1.00021545, expected 1.00000000, off by 2.15e-04 |
| independent propagation | coupler_length075: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.3e-11 of its peak |
| directional couplers | coupler_length075: power bar 0.149724082 2e-7 | PASS | 0.14972408, expected 0.14972408, off by -2.20e-11 |
| directional couplers | coupler_length075: power cross 0.849895891 2e-7 | PASS | 0.84989589, expected 0.84989589, off by -2.24e-10 |
| directional couplers | coupler_length075: neff 2.632698756 2e-8 | PASS | 2.63269876, expected 2.63269876, off by 4.68e-10 |
| directional couplers | coupler_length075: power cross 0.85355 0.02 | PASS | 0.84989589, expected 0.85355000, off by -3.65e-03 |
| directional couplers | coupler_length075: sum bar cross 1.0 2e-3 | PASS | 0.99961997, expected 1.00000000, off by -3.80e-04 |
| independent propagation | coupler_length150: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 4.2e-11 of its peak |
| directional couplers | coupler_length150: power bar 0.496718241 2e-7 | PASS | 0.49671824, expected 0.49671824, off by 2.06e-10 |
| directional couplers | coupler_length150: power cross 0.504989553 2e-7 | PASS | 0.50498955, expected 0.50498955, off by 3.02e-10 |
| directional couplers | coupler_length150: neff 2.655703472 2e-8 | PASS | 2.65570347, expected 2.65570347, off by 2.56e-10 |
| directional couplers | coupler_length150: power cross 0.50000 0.02 | PASS | 0.50498955, expected 0.50000000, off by 4.99e-03 |
| directional couplers | coupler_length150: sum bar cross 1.0 2e-3 | PASS | 1.00170779, expected 1.00000000, off by 1.71e-03 |
| independent propagation | free_tilt02: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.7e-11 of its peak |
| free propagation | free_tilt02: total end 1.000000000 2e-7 | PASS | 1.00000000, expected 1.00000000, off by -4.70e-10 |
| free propagation | free_tilt02: centroid end 3.4893811 2e-6 | PASS | 3.48938111, expected 3.48938110, off by 7.43e-09 |
| free propagation | free_tilt02: radius end 11.7754812 2e-6 | PASS | 11.77548121, expected 11.77548120, off by 9.18e-09 |
| free propagation | free_tilt02: neff 1.442469491 2e-8 | PASS | 1.44246949, expected 1.44246949, off by -2.40e-11 |
| free propagation | free_tilt02: centroid end 3.48995 0.02 | PASS | 3.48938111, expected 3.48995000, off by -5.69e-04 |
| free propagation | free_tilt02: radius end 11.77769 0.04 | PASS | 11.77548121, expected 11.77769000, off by -2.21e-03 |
| independent propagation | free_tilt05: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.5e-11 of its peak |
| free propagation | free_tilt05: total end 0.999999919 2e-7 | PASS | 0.99999992, expected 0.99999992, off by 3.76e-10 |
| free propagation | free_tilt05: centroid end 8.7132818 2e-6 | PASS | 8.71328178, expected 8.71328180, off by -2.15e-08 |
| free propagation | free_tilt05: radius end 11.7721289 2e-6 | PASS | 11.77212888, expected 11.77212890, off by -1.79e-08 |
| free propagation | free_tilt05: neff 1.441469018 2e-8 | PASS | 1.44146902, expected 1.44146902, off by 1.44e-10 |
| free propagation | free_tilt05: centroid end 8.71557 0.02 | PASS | 8.71328178, expected 8.71557000, off by -2.29e-03 |
| free propagation | free_tilt05: radius end 11.77769 0.04 | PASS | 11.77212888, expected 11.77769000, off by -5.56e-03 |
| independent propagation | free_tilt10: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.6e-11 of its peak |
| free propagation | free_tilt10: total end 0.999923063 2e-7 | PASS | 0.99992306, expected 0.99992306, off by 6.49e-11 |
| free propagation | free_tilt10: centroid end 17.3519344 2e-6 | PASS | 17.35193437, expected 17.35193440, off by -2.66e-08 |
| free propagation | free_tilt10: radius end 11.7523046 2e-6 | PASS | 11.75230464, expected 11.75230460, off by 4.17e-08 |
| free propagation | free_tilt10: neff 1.437930599 2e-8 | PASS | 1.43793060, expected 1.43793060, off by 4.87e-10 |
| free propagation | free_tilt10: centroid end 17.36482 0.02 | PASS | 17.35193437, expected 17.36482000, off by -1.29e-02 |
| free propagation | free_tilt10: radius end 11.77769 0.04 | PASS | 11.75230464, expected 11.77769000, off by -2.54e-02 |
| independent propagation | free_w10: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.3e-11 of its peak |
| free propagation | free_w10: total end 1.000000000 2e-7 | PASS | 1.00000000, expected 1.00000000, off by -1.78e-13 |
| free propagation | free_w10: centroid end 0.0000000 2e-6 | PASS | -0.00000000, expected 0.00000000, off by -2.64e-14 |
| free propagation | free_w10: radius end 20.5098292 2e-6 | PASS | 20.50982921, expected 20.50982920, off by 1.39e-08 |
| free propagation | free_w10: neff 1.440970725 2e-8 | PASS | 1.44097072, expected 1.44097072, off by -1.95e-11 |
| free propagation | free_w10: radius end 20.52494 0.0821 | PASS | 20.50982921, expected 20.52494000, off by -1.51e-02 |
| free propagation | free_w10: conserved 1e-6 | PASS | largest change of the total power 1.82e-13 over 480 steps of 0.125 um |
| free propagation | free_w10: centroid end 0 1e-6 | PASS | -0.00000000, expected 0.00000000, off by -2.64e-14 |
| independent propagation | free_w15: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.5e-11 of its peak |
| free propagation | free_w15: total end 1.000000000 2e-7 | PASS | 1.00000000, expected 1.00000000, off by 2.22e-13 |
| free propagation | free_w15: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 1.88e-14 |
| free propagation | free_w15: radius end 22.8074849 2e-6 | PASS | 22.80748486, expected 22.80748490, off by -3.75e-08 |
| free propagation | free_w15: neff 1.442223977 2e-8 | PASS | 1.44222398, expected 1.44222398, off by -3.66e-10 |
| free propagation | free_w15: radius end 22.82774 0.0913 | PASS | 22.80748486, expected 22.82774000, off by -2.03e-02 |
| free propagation | free_w15: conserved 1e-6 | PASS | largest change of the total power 2.23e-13 over 400 steps of 0.250 um |
| free propagation | free_w15: centroid end 0 1e-6 | PASS | 0.00000000, expected 0.00000000, off by 1.88e-14 |
| independent propagation | free_w20: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.7e-11 of its peak |
| free propagation | free_w20: total end 1.000000000 2e-7 | PASS | 1.00000000, expected 1.00000000, off by 3.30e-13 |
| free propagation | free_w20: centroid end -0.0000000 2e-6 | PASS | -0.00000000, expected -0.00000000, off by -5.52e-15 |
| free propagation | free_w20: radius end 25.6929320 2e-6 | PASS | 25.69293199, expected 25.69293200, off by -6.76e-09 |
| free propagation | free_w20: neff 1.442835642 2e-8 | PASS | 1.44283564, expected 1.44283564, off by 4.47e-10 |
| free propagation | free_w20: radius end 25.70364 0.1028 | PASS | 25.69293199, expected 25.70364000, off by -1.07e-02 |
| free propagation | free_w20: conserved 1e-6 | PASS | largest change of the total power 3.30e-13 over 600 steps of 0.250 um |
| free propagation | free_w20: centroid end 0 1e-6 | PASS | -0.00000000, expected 0.00000000, off by -5.52e-15 |
| independent propagation | free_w30: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.5e-11 of its peak |
| free propagation | free_w30: total end 1.000000000 2e-7 | PASS | 1.00000000, expected 1.00000000, off by 4.43e-13 |
| free propagation | free_w30: centroid end -0.0000000 2e-6 | PASS | -0.00000000, expected -0.00000000, off by -1.35e-14 |
| free propagation | free_w30: radius end 22.9715019 2e-6 | PASS | 22.97150191, expected 22.97150190, off by 1.09e-08 |
| free propagation | free_w30: neff 1.443190083 2e-8 | PASS | 1.44319008, expected 1.44319008, off by -4.30e-10 |
| free propagation | free_w30: radius end 22.97511 0.0919 | PASS | 22.97150191, expected 22.97511000, off by -3.61e-03 |
| free propagation | free_w30: conserved 1e-6 | PASS | largest change of the total power 4.43e-13 over 800 steps of 0.250 um |
| free propagation | free_w30: centroid end 0 1e-6 | PASS | -0.00000000, expected 0.00000000, off by -1.35e-14 |
| independent propagation | free_w50: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.3e-11 of its peak |
| free propagation | free_w50: total end 1.000000000 2e-7 | PASS | 1.00000000, expected 1.00000000, off by 6.71e-13 |
| free propagation | free_w50: centroid end 0.0000000 2e-6 | PASS | -0.00000000, expected 0.00000000, off by -2.30e-14 |
| free propagation | free_w50: radius end 21.1004489 2e-6 | PASS | 21.10044887, expected 21.10044890, off by -2.52e-08 |
| free propagation | free_w50: neff 1.443540758 2e-8 | PASS | 1.44354076, expected 1.44354076, off by -2.91e-10 |
| free propagation | free_w50: radius end 21.10150 0.0844 | PASS | 21.10044887, expected 21.10150000, off by -1.05e-03 |
| free propagation | free_w50: conserved 1e-6 | PASS | largest change of the total power 6.71e-13 over 1200 steps of 0.250 um |
| free propagation | free_w50: centroid end 0 1e-6 | PASS | -0.00000000, expected 0.00000000, off by -2.30e-14 |
| independent propagation | grid_dx125: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.0e-11 of its peak |
| step and grid | grid_dx125: power bar 0.003581549 2e-7 | PASS | 0.00358155, expected 0.00358155, off by 2.57e-11 |
| step and grid | grid_dx125: power cross 0.997591306 2e-7 | PASS | 0.99759131, expected 0.99759131, off by 3.59e-10 |
| step and grid | grid_dx125: neff 2.643404380 2e-8 | PASS | 2.64340438, expected 2.64340438, off by -3.91e-11 |
| independent propagation | grid_dx250: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.0e-11 of its peak |
| step and grid | grid_dx250: power bar 0.003513231 2e-7 | PASS | 0.00351323, expected 0.00351323, off by 3.96e-10 |
| step and grid | grid_dx250: power cross 0.997785186 2e-7 | PASS | 0.99778519, expected 0.99778519, off by -2.81e-11 |
| step and grid | grid_dx250: neff 2.644389067 2e-8 | PASS | 2.64438907, expected 2.64438907, off by 3.36e-10 |
| independent propagation | grid_dx500: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.3e-11 of its peak |
| step and grid | grid_dx500: power bar 0.003280024 2e-7 | PASS | 0.00328002, expected 0.00328002, off by -1.31e-10 |
| step and grid | grid_dx500: power cross 0.998511123 2e-7 | PASS | 0.99851112, expected 0.99851112, off by 3.88e-10 |
| step and grid | grid_dx500: neff 2.648206766 2e-8 | PASS | 2.64820677, expected 2.64820677, off by 1.52e-10 |
| independent propagation | launch_offset100: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.7e-11 of its peak |
| launch conditions | launch_offset100: power out 0.873824234 2e-7 | PASS | 0.87382423, expected 0.87382423, off by 4.57e-10 |
| launch conditions | launch_offset100: total end 0.989104493 2e-7 | PASS | 0.98910449, expected 0.98910449, off by -9.73e-11 |
| launch conditions | launch_offset100: centroid end -0.0335733 2e-6 | PASS | -0.03357331, expected -0.03357330, off by -1.41e-08 |
| launch conditions | launch_offset100: radius end 0.6758767 2e-6 | PASS | 0.67587669, expected 0.67587670, off by -1.39e-08 |
| launch conditions | launch_offset100: neff 2.629142305 2e-8 | PASS | 2.62914231, expected 2.62914230, off by 4.37e-10 |
| launch conditions | launch_offset100: power out 0.87391 2e-3 | PASS | 0.87382423, expected 0.87391000, off by -8.58e-05 |
| independent propagation | launch_offset200: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.4e-11 of its peak |
| launch conditions | launch_offset200: power out 0.586370473 2e-7 | PASS | 0.58637047, expected 0.58637047, off by -8.25e-11 |
| launch conditions | launch_offset200: total end 0.901189616 2e-7 | PASS | 0.90118962, expected 0.90118962, off by -3.68e-10 |
| launch conditions | launch_offset200: centroid end -0.0551789 2e-6 | PASS | -0.05517886, expected -0.05517890, off by 3.83e-08 |
| launch conditions | launch_offset200: radius end 1.2884561 2e-6 | PASS | 1.28845611, expected 1.28845610, off by 7.80e-09 |
| launch conditions | launch_offset200: neff 2.629660990 2e-8 | PASS | 2.62966099, expected 2.62966099, off by 4.14e-10 |
| launch conditions | launch_offset200: power out 0.58658 2e-3 | PASS | 0.58637047, expected 0.58658000, off by -2.10e-04 |
| independent propagation | launch_offset300: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.8e-11 of its peak |
| launch conditions | launch_offset300: power out 0.303768860 2e-7 | PASS | 0.30376886, expected 0.30376886, off by 1.78e-10 |
| launch conditions | launch_offset300: total end 0.683233365 2e-7 | PASS | 0.68323337, expected 0.68323336, off by 1.06e-10 |
| launch conditions | launch_offset300: centroid end -0.0847219 2e-6 | PASS | -0.08472193, expected -0.08472190, off by -2.89e-08 |
| launch conditions | launch_offset300: radius end 2.1289405 2e-6 | PASS | 2.12894047, expected 2.12894050, off by -3.12e-08 |
| launch conditions | launch_offset300: neff 2.041353351 2e-8 | PASS | 2.04135335, expected 2.04135335, off by 1.74e-10 |
| launch conditions | launch_offset300: power out 0.30399 2e-3 | PASS | 0.30376886, expected 0.30399000, off by -2.21e-04 |
| independent propagation | launch_w400_into_w500: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.8e-11 of its peak |
| launch conditions | launch_w400_into_w500: power out 0.993403006 2e-7 | PASS | 0.99340301, expected 0.99340301, off by 2.10e-10 |
| launch conditions | launch_w400_into_w500: total end 0.993901432 2e-7 | PASS | 0.99390143, expected 0.99390143, off by -4.59e-10 |
| launch conditions | launch_w400_into_w500: centroid end 0.0000000 2e-6 | PASS | -0.00000000, expected 0.00000000, off by -3.48e-15 |
| launch conditions | launch_w400_into_w500: radius end 0.4021919 2e-6 | PASS | 0.40219195, expected 0.40219190, off by 4.60e-08 |
| launch conditions | launch_w400_into_w500: neff 2.630160827 2e-8 | PASS | 2.63016083, expected 2.63016083, off by -3.13e-10 |
| launch conditions | launch_w400_into_w500: power out 0.99329 2e-3 | PASS | 0.99340301, expected 0.99329000, off by 1.13e-04 |
| independent propagation | launch_w500_into_w1200: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.8e-11 of its peak |
| launch conditions | launch_w500_into_w1200: power out 0.810773831 2e-7 | PASS | 0.81077383, expected 0.81077383, off by 7.81e-11 |
| launch conditions | launch_w500_into_w1200: total end 0.986458319 2e-7 | PASS | 0.98645832, expected 0.98645832, off by -5.99e-11 |
| launch conditions | launch_w500_into_w1200: centroid end -0.0000000 2e-6 | PASS | -0.00000000, expected -0.00000000, off by -3.22e-16 |
| launch conditions | launch_w500_into_w1200: radius end 0.5765433 2e-6 | PASS | 0.57654326, expected 0.57654330, off by -3.85e-08 |
| launch conditions | launch_w500_into_w1200: neff 2.798893919 2e-8 | PASS | 2.79889392, expected 2.79889392, off by 1.50e-10 |
| launch conditions | launch_w500_into_w1200: power out 0.81087 2e-3 | PASS | 0.81077383, expected 0.81087000, off by -9.62e-05 |
| independent propagation | launch_w500_into_w800: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.5e-11 of its peak |
| launch conditions | launch_w500_into_w800: power out 0.947444027 2e-7 | PASS | 0.94744403, expected 0.94744403, off by 4.37e-10 |
| launch conditions | launch_w500_into_w800: total end 0.995535837 2e-7 | PASS | 0.99553584, expected 0.99553584, off by 4.08e-10 |
| launch conditions | launch_w500_into_w800: centroid end 0.0000000 2e-6 | PASS | -0.00000000, expected 0.00000000, off by -2.23e-15 |
| launch conditions | launch_w500_into_w800: radius end 0.4891702 2e-6 | PASS | 0.48917022, expected 0.48917020, off by 2.23e-08 |
| launch conditions | launch_w500_into_w800: neff 2.744054182 2e-8 | PASS | 2.74405418, expected 2.74405418, off by 5.30e-11 |
| launch conditions | launch_w500_into_w800: power out 0.94761 2e-3 | PASS | 0.94744403, expected 0.94761000, off by -1.66e-04 |
| independent propagation | launch_w800_into_w500: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.1e-11 of its peak |
| launch conditions | launch_w800_into_w500: power out 0.947357954 2e-7 | PASS | 0.94735795, expected 0.94735795, off by -2.75e-10 |
| launch conditions | launch_w800_into_w500: total end 0.950995199 2e-7 | PASS | 0.95099520, expected 0.95099520, off by -2.38e-10 |
| launch conditions | launch_w800_into_w500: centroid end -0.0000000 2e-6 | PASS | -0.00000000, expected -0.00000000, off by -2.34e-16 |
| launch conditions | launch_w800_into_w500: radius end 0.9506654 2e-6 | PASS | 0.95066540, expected 0.95066540, off by -2.37e-09 |
| launch conditions | launch_w800_into_w500: neff 2.631410284 2e-8 | PASS | 2.63141028, expected 2.63141028, off by -8.88e-11 |
| launch conditions | launch_w800_into_w500: power out 0.94761 2e-3 | PASS | 0.94735795, expected 0.94761000, off by -2.52e-04 |
| independent propagation | mmi_1x2_w4_l090: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 8.6e-12 of its peak |
| multimode interferometers | mmi_1x2_w4_l090: power upper 0.422971517 2e-7 | PASS | 0.42297152, expected 0.42297152, off by -1.73e-10 |
| multimode interferometers | mmi_1x2_w4_l090: power lower 0.422971517 2e-7 | PASS | 0.42297152, expected 0.42297152, off by -1.73e-10 |
| multimode interferometers | mmi_1x2_w4_l090: total end 0.996305075 2e-7 | PASS | 0.99630507, expected 0.99630507, off by -2.42e-10 |
| multimode interferometers | mmi_1x2_w4_l090: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 2.90e-14 |
| multimode interferometers | mmi_1x2_w4_l090: radius end 2.8263656 2e-6 | PASS | 2.82636563, expected 2.82636560, off by 2.88e-08 |
| multimode interferometers | mmi_1x2_w4_l090: neff 2.655973267 2e-8 | PASS | 2.65597327, expected 2.65597327, off by -6.65e-11 |
| multimode interferometers | mmi_1x2_w4_l090: ratio upper lower 1.0 1e-4 | PASS | 1.00000000, expected 1.00000000, off by 5.44e-14 |
| independent propagation | mmi_1x2_w4_l100: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 7.3e-12 of its peak |
| multimode interferometers | mmi_1x2_w4_l100: power upper 0.493043513 2e-7 | PASS | 0.49304351, expected 0.49304351, off by 2.47e-10 |
| multimode interferometers | mmi_1x2_w4_l100: power lower 0.493043513 2e-7 | PASS | 0.49304351, expected 0.49304351, off by 2.47e-10 |
| multimode interferometers | mmi_1x2_w4_l100: total end 0.999694486 2e-7 | PASS | 0.99969449, expected 0.99969449, off by 2.71e-10 |
| multimode interferometers | mmi_1x2_w4_l100: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 3.76e-14 |
| multimode interferometers | mmi_1x2_w4_l100: radius end 2.0186846 2e-6 | PASS | 2.01868458, expected 2.01868460, off by -2.11e-08 |
| multimode interferometers | mmi_1x2_w4_l100: neff 2.812129982 2e-8 | PASS | 2.81212998, expected 2.81212998, off by -3.47e-10 |
| multimode interferometers | mmi_1x2_w4_l100: ratio upper lower 1.0 1e-4 | PASS | 1.00000000, expected 1.00000000, off by 8.17e-14 |
| multimode interferometers | mmi_1x2_w4_l100: power_above upper 0.46 | PASS | 0.493044 against the bound 0.460000 (margin 3.30e-02) |
| independent propagation | mmi_1x2_w4_l110: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 8.1e-12 of its peak |
| multimode interferometers | mmi_1x2_w4_l110: power upper 0.442176577 2e-7 | PASS | 0.44217658, expected 0.44217658, off by 2.36e-10 |
| multimode interferometers | mmi_1x2_w4_l110: power lower 0.442176577 2e-7 | PASS | 0.44217658, expected 0.44217658, off by 2.36e-10 |
| multimode interferometers | mmi_1x2_w4_l110: total end 0.995438652 2e-7 | PASS | 0.99543865, expected 0.99543865, off by -3.06e-11 |
| multimode interferometers | mmi_1x2_w4_l110: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 3.67e-14 |
| multimode interferometers | mmi_1x2_w4_l110: radius end 2.6123491 2e-6 | PASS | 2.61234912, expected 2.61234910, off by 1.89e-08 |
| multimode interferometers | mmi_1x2_w4_l110: neff 2.701909128 2e-8 | PASS | 2.70190913, expected 2.70190913, off by -2.44e-10 |
| multimode interferometers | mmi_1x2_w4_l110: ratio upper lower 1.0 1e-4 | PASS | 1.00000000, expected 1.00000000, off by 8.28e-14 |
| independent propagation | mmi_1x2_w6_l080: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 9.8e-12 of its peak |
| multimode interferometers | mmi_1x2_w6_l080: power upper 0.184214736 2e-7 | PASS | 0.18421474, expected 0.18421474, off by 4.29e-10 |
| multimode interferometers | mmi_1x2_w6_l080: power lower 0.184214736 2e-7 | PASS | 0.18421474, expected 0.18421474, off by 4.29e-10 |
| multimode interferometers | mmi_1x2_w6_l080: total end 0.996871835 2e-7 | PASS | 0.99687184, expected 0.99687183, off by 9.76e-11 |
| multimode interferometers | mmi_1x2_w6_l080: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 5.76e-14 |
| multimode interferometers | mmi_1x2_w6_l080: radius end 5.5391273 2e-6 | PASS | 5.53912727, expected 5.53912730, off by -3.24e-08 |
| multimode interferometers | mmi_1x2_w6_l080: neff 2.545685461 2e-8 | PASS | 2.54568546, expected 2.54568546, off by 1.73e-10 |
| multimode interferometers | mmi_1x2_w6_l080: ratio upper lower 1.0 1e-4 | PASS | 1.00000000, expected 1.00000000, off by 1.04e-13 |
| independent propagation | mmi_1x2_w6_l090: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 1.1e-11 of its peak |
| multimode interferometers | mmi_1x2_w6_l090: power upper 0.301496210 2e-7 | PASS | 0.30149621, expected 0.30149621, off by 1.15e-10 |
| multimode interferometers | mmi_1x2_w6_l090: power lower 0.301496210 2e-7 | PASS | 0.30149621, expected 0.30149621, off by 1.15e-10 |
| multimode interferometers | mmi_1x2_w6_l090: total end 0.997659545 2e-7 | PASS | 0.99765955, expected 0.99765954, off by 9.41e-11 |
| multimode interferometers | mmi_1x2_w6_l090: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 2.50e-14 |
| multimode interferometers | mmi_1x2_w6_l090: radius end 4.5241804 2e-6 | PASS | 4.52418040, expected 4.52418040, off by -8.37e-10 |
| multimode interferometers | mmi_1x2_w6_l090: neff 2.563447407 2e-8 | PASS | 2.56344741, expected 2.56344741, off by -4.95e-10 |
| multimode interferometers | mmi_1x2_w6_l090: ratio upper lower 1.0 1e-4 | PASS | 1.00000000, expected 1.00000000, off by 7.44e-14 |
| independent propagation | mmi_1x2_w6_l100: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 7.3e-12 of its peak |
| multimode interferometers | mmi_1x2_w6_l100: power upper 0.492198439 2e-7 | PASS | 0.49219844, expected 0.49219844, off by 1.27e-10 |
| multimode interferometers | mmi_1x2_w6_l100: power lower 0.492198439 2e-7 | PASS | 0.49219844, expected 0.49219844, off by 1.27e-10 |
| multimode interferometers | mmi_1x2_w6_l100: total end 0.999576286 2e-7 | PASS | 0.99957629, expected 0.99957629, off by -1.16e-10 |
| multimode interferometers | mmi_1x2_w6_l100: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 3.92e-14 |
| multimode interferometers | mmi_1x2_w6_l100: radius end 2.9972900 2e-6 | PASS | 2.99728996, expected 2.99729000, off by -4.40e-08 |
| multimode interferometers | mmi_1x2_w6_l100: neff 2.631321475 2e-8 | PASS | 2.63132147, expected 2.63132148, off by -2.54e-10 |
| multimode interferometers | mmi_1x2_w6_l100: ratio upper lower 1.0 1e-4 | PASS | 1.00000000, expected 1.00000000, off by 5.44e-14 |
| multimode interferometers | mmi_1x2_w6_l100: power_above upper 0.46 | PASS | 0.492198 against the bound 0.460000 (margin 3.22e-02) |
| independent propagation | mmi_1x2_w6_l110: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 1.1e-11 of its peak |
| multimode interferometers | mmi_1x2_w6_l110: power upper 0.308522999 2e-7 | PASS | 0.30852300, expected 0.30852300, off by -3.01e-10 |
| multimode interferometers | mmi_1x2_w6_l110: power lower 0.308522999 2e-7 | PASS | 0.30852300, expected 0.30852300, off by -3.01e-10 |
| multimode interferometers | mmi_1x2_w6_l110: total end 0.993021496 2e-7 | PASS | 0.99302150, expected 0.99302150, off by 4.68e-10 |
| multimode interferometers | mmi_1x2_w6_l110: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 3.00e-14 |
| multimode interferometers | mmi_1x2_w6_l110: radius end 5.2332671 2e-6 | PASS | 5.23326708, expected 5.23326710, off by -1.57e-08 |
| multimode interferometers | mmi_1x2_w6_l110: neff 2.578655314 2e-8 | PASS | 2.57865531, expected 2.57865531, off by 4.78e-10 |
| multimode interferometers | mmi_1x2_w6_l110: ratio upper lower 1.0 1e-4 | PASS | 1.00000000, expected 1.00000000, off by 4.97e-14 |
| independent propagation | mmi_1x2_w6_l120: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 9.9e-12 of its peak |
| multimode interferometers | mmi_1x2_w6_l120: power upper 0.183325672 2e-7 | PASS | 0.18332567, expected 0.18332567, off by -1.97e-10 |
| multimode interferometers | mmi_1x2_w6_l120: power lower 0.183325672 2e-7 | PASS | 0.18332567, expected 0.18332567, off by -1.97e-10 |
| multimode interferometers | mmi_1x2_w6_l120: total end 0.997743736 2e-7 | PASS | 0.99774374, expected 0.99774374, off by 4.31e-10 |
| multimode interferometers | mmi_1x2_w6_l120: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 2.23e-14 |
| multimode interferometers | mmi_1x2_w6_l120: radius end 5.3174712 2e-6 | PASS | 5.31747120, expected 5.31747120, off by 1.76e-09 |
| multimode interferometers | mmi_1x2_w6_l120: neff 2.590741871 2e-8 | PASS | 2.59074187, expected 2.59074187, off by -4.07e-10 |
| multimode interferometers | mmi_1x2_w6_l120: ratio upper lower 1.0 1e-4 | PASS | 1.00000000, expected 1.00000000, off by 1.01e-13 |
| independent propagation | mmi_1x2_w8_l090: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 1.2e-11 of its peak |
| multimode interferometers | mmi_1x2_w8_l090: power upper 0.198875398 2e-7 | PASS | 0.19887540, expected 0.19887540, off by 4.77e-11 |
| multimode interferometers | mmi_1x2_w8_l090: power lower 0.198875398 2e-7 | PASS | 0.19887540, expected 0.19887540, off by 4.77e-11 |
| multimode interferometers | mmi_1x2_w8_l090: total end 0.996475741 2e-7 | PASS | 0.99647574, expected 0.99647574, off by -4.78e-11 |
| multimode interferometers | mmi_1x2_w8_l090: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 4.68e-14 |
| multimode interferometers | mmi_1x2_w8_l090: radius end 5.8317856 2e-6 | PASS | 5.83178562, expected 5.83178560, off by 1.99e-08 |
| multimode interferometers | mmi_1x2_w8_l090: neff 2.632269826 2e-8 | PASS | 2.63226983, expected 2.63226983, off by -2.03e-10 |
| multimode interferometers | mmi_1x2_w8_l090: ratio upper lower 1.0 1e-4 | PASS | 1.00000000, expected 1.00000000, off by 7.97e-14 |
| independent propagation | mmi_1x2_w8_l100: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 7.1e-12 of its peak |
| multimode interferometers | mmi_1x2_w8_l100: power upper 0.490201023 2e-7 | PASS | 0.49020102, expected 0.49020102, off by 2.67e-10 |
| multimode interferometers | mmi_1x2_w8_l100: power lower 0.490201023 2e-7 | PASS | 0.49020102, expected 0.49020102, off by 2.67e-10 |
| multimode interferometers | mmi_1x2_w8_l100: total end 0.999507279 2e-7 | PASS | 0.99950728, expected 0.99950728, off by 3.97e-10 |
| multimode interferometers | mmi_1x2_w8_l100: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 2.88e-14 |
| multimode interferometers | mmi_1x2_w8_l100: radius end 3.9993928 2e-6 | PASS | 3.99939282, expected 3.99939280, off by 1.54e-08 |
| multimode interferometers | mmi_1x2_w8_l100: neff 2.624261259 2e-8 | PASS | 2.62426126, expected 2.62426126, off by 3.37e-10 |
| multimode interferometers | mmi_1x2_w8_l100: ratio upper lower 1.0 1e-4 | PASS | 1.00000000, expected 1.00000000, off by 2.53e-14 |
| multimode interferometers | mmi_1x2_w8_l100: power_above upper 0.46 | PASS | 0.490201 against the bound 0.460000 (margin 3.02e-02) |
| independent propagation | mmi_1x2_w8_l110: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 1.1e-11 of its peak |
| multimode interferometers | mmi_1x2_w8_l110: power upper 0.193124693 2e-7 | PASS | 0.19312469, expected 0.19312469, off by -4.65e-12 |
| multimode interferometers | mmi_1x2_w8_l110: power lower 0.193124693 2e-7 | PASS | 0.19312469, expected 0.19312469, off by -4.65e-12 |
| multimode interferometers | mmi_1x2_w8_l110: total end 0.996563761 2e-7 | PASS | 0.99656376, expected 0.99656376, off by -2.08e-10 |
| multimode interferometers | mmi_1x2_w8_l110: centroid end 0.0000000 2e-6 | PASS | -0.00000000, expected 0.00000000, off by -5.07e-15 |
| multimode interferometers | mmi_1x2_w8_l110: radius end 6.9970547 2e-6 | PASS | 6.99705472, expected 6.99705470, off by 2.13e-08 |
| multimode interferometers | mmi_1x2_w8_l110: neff 2.645768098 2e-8 | PASS | 2.64576810, expected 2.64576810, off by -1.32e-11 |
| multimode interferometers | mmi_1x2_w8_l110: ratio upper lower 1.0 1e-4 | PASS | 1.00000000, expected 1.00000000, off by -6.00e-15 |
| independent propagation | mmi_2x2_l090: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 9.5e-12 of its peak |
| multimode interferometers | mmi_2x2_l090: power bar 0.216899940 2e-7 | PASS | 0.21689994, expected 0.21689994, off by -2.08e-11 |
| multimode interferometers | mmi_2x2_l090: power cross 0.292916356 2e-7 | PASS | 0.29291636, expected 0.29291636, off by -2.45e-13 |
| multimode interferometers | mmi_2x2_l090: total end 0.997776434 2e-7 | PASS | 0.99777643, expected 0.99777643, off by -3.78e-10 |
| multimode interferometers | mmi_2x2_l090: centroid end 0.1966037 2e-6 | PASS | 0.19660372, expected 0.19660370, off by 1.92e-08 |
| multimode interferometers | mmi_2x2_l090: radius end 3.8802030 2e-6 | PASS | 3.88020303, expected 3.88020300, off by 2.96e-08 |
| multimode interferometers | mmi_2x2_l090: neff 2.824706188 2e-8 | PASS | 2.82470619, expected 2.82470619, off by -1.01e-10 |
| independent propagation | mmi_2x2_l100: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 9.3e-12 of its peak |
| multimode interferometers | mmi_2x2_l100: power bar 0.491349109 2e-7 | PASS | 0.49134911, expected 0.49134911, off by -1.50e-10 |
| multimode interferometers | mmi_2x2_l100: power cross 0.487436907 2e-7 | PASS | 0.48743691, expected 0.48743691, off by -4.34e-10 |
| multimode interferometers | mmi_2x2_l100: total end 0.999376634 2e-7 | PASS | 0.99937663, expected 0.99937663, off by -2.13e-10 |
| multimode interferometers | mmi_2x2_l100: centroid end 0.0026461 2e-6 | PASS | 0.00264607, expected 0.00264610, off by -3.23e-08 |
| multimode interferometers | mmi_2x2_l100: radius end 2.2348449 2e-6 | PASS | 2.23484491, expected 2.23484490, off by 5.79e-09 |
| multimode interferometers | mmi_2x2_l100: neff 2.824894866 2e-8 | PASS | 2.82489487, expected 2.82489487, off by 8.41e-11 |
| multimode interferometers | mmi_2x2_l100: sum bar cross 0.9 0.1 | PASS | 0.97878602, expected 0.90000000, off by 7.88e-02 |
| multimode interferometers | mmi_2x2_l100: ratio bar cross 1.0 0.15 | PASS | 1.00802607, expected 1.00000000, off by 8.03e-03 |
| independent propagation | mmi_2x2_l110: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 8.4e-12 of its peak |
| multimode interferometers | mmi_2x2_l110: power bar 0.283832912 2e-7 | PASS | 0.28383291, expected 0.28383291, off by 3.26e-10 |
| multimode interferometers | mmi_2x2_l110: power cross 0.221306911 2e-7 | PASS | 0.22130691, expected 0.22130691, off by -2.82e-10 |
| multimode interferometers | mmi_2x2_l110: total end 0.997010856 2e-7 | PASS | 0.99701086, expected 0.99701086, off by 2.16e-10 |
| multimode interferometers | mmi_2x2_l110: centroid end 0.2415539 2e-6 | PASS | 0.24155388, expected 0.24155390, off by -1.62e-08 |
| multimode interferometers | mmi_2x2_l110: radius end 5.3020129 2e-6 | PASS | 5.30201291, expected 5.30201290, off by 6.58e-09 |
| multimode interferometers | mmi_2x2_l110: neff 2.824166898 2e-8 | PASS | 2.82416690, expected 2.82416690, off by -2.29e-11 |
| independent propagation | sbend_off1_l10: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.8e-11 of its peak |
| s-bends | sbend_off1_l10: power out 0.998061697 2e-7 | PASS | 0.99806170, expected 0.99806170, off by 4.33e-10 |
| s-bends | sbend_off1_l10: total end 0.999999819 2e-7 | PASS | 0.99999982, expected 0.99999982, off by -5.88e-11 |
| s-bends | sbend_off1_l10: centroid end 0.9933069 2e-6 | PASS | 0.99330687, expected 0.99330690, off by -3.08e-08 |
| s-bends | sbend_off1_l10: radius end 0.2795752 2e-6 | PASS | 0.27957519, expected 0.27957520, off by -1.17e-08 |
| s-bends | sbend_off1_l10: neff 2.633014842 2e-8 | PASS | 2.63301484, expected 2.63301484, off by -1.45e-10 |
| independent propagation | sbend_off1_l20: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.0e-11 of its peak |
| s-bends | sbend_off1_l20: power out 0.999942229 2e-7 | PASS | 0.99994223, expected 0.99994223, off by -3.49e-10 |
| s-bends | sbend_off1_l20: total end 0.999999370 2e-7 | PASS | 0.99999937, expected 0.99999937, off by 2.41e-10 |
| s-bends | sbend_off1_l20: centroid end 0.9994644 2e-6 | PASS | 0.99946443, expected 0.99946440, off by 2.63e-08 |
| s-bends | sbend_off1_l20: radius end 0.2805361 2e-6 | PASS | 0.28053609, expected 0.28053610, off by -1.36e-08 |
| s-bends | sbend_off1_l20: neff 2.631211287 2e-8 | PASS | 2.63121129, expected 2.63121129, off by -2.34e-10 |
| independent propagation | sbend_off1_l40: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.0e-11 of its peak |
| s-bends | sbend_off1_l40: power out 0.999938441 2e-7 | PASS | 0.99993844, expected 0.99993844, off by 3.18e-10 |
| s-bends | sbend_off1_l40: total end 0.999994823 2e-7 | PASS | 0.99999482, expected 0.99999482, off by -3.29e-10 |
| s-bends | sbend_off1_l40: centroid end 1.0004388 2e-6 | PASS | 1.00043881, expected 1.00043880, off by 7.24e-09 |
| s-bends | sbend_off1_l40: radius end 0.2867538 2e-6 | PASS | 0.28675379, expected 0.28675380, off by -9.29e-09 |
| s-bends | sbend_off1_l40: neff 2.629815680 2e-8 | PASS | 2.62981568, expected 2.62981568, off by 1.14e-10 |
| independent propagation | sbend_off2_l20: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.9e-11 of its peak |
| s-bends | sbend_off2_l20: power out 0.999657829 2e-7 | PASS | 0.99965783, expected 0.99965783, off by -2.26e-10 |
| s-bends | sbend_off2_l20: total end 0.999999304 2e-7 | PASS | 0.99999930, expected 0.99999930, off by 5.27e-11 |
| s-bends | sbend_off2_l20: centroid end 2.0002782 2e-6 | PASS | 2.00027821, expected 2.00027820, off by 1.04e-08 |
| s-bends | sbend_off2_l20: radius end 0.2843038 2e-6 | PASS | 0.28430378, expected 0.28430380, off by -1.78e-08 |
| s-bends | sbend_off2_l20: neff 2.178196218 2e-8 | PASS | 2.17819622, expected 2.17819622, off by 1.93e-10 |
| independent propagation | sbend_off2_l40: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.9e-11 of its peak |
| s-bends | sbend_off2_l40: power out 0.999869352 2e-7 | PASS | 0.99986935, expected 0.99986935, off by 2.91e-11 |
| s-bends | sbend_off2_l40: total end 0.999995543 2e-7 | PASS | 0.99999554, expected 0.99999554, off by 3.09e-10 |
| s-bends | sbend_off2_l40: centroid end 2.0008950 2e-6 | PASS | 2.00089495, expected 2.00089500, off by -4.90e-08 |
| s-bends | sbend_off2_l40: radius end 0.2819521 2e-6 | PASS | 0.28195210, expected 0.28195210, off by 1.59e-09 |
| s-bends | sbend_off2_l40: neff 2.232755841 2e-8 | PASS | 2.23275584, expected 2.23275584, off by -3.14e-10 |
| independent propagation | sbend_off2_l80: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.0e-11 of its peak |
| s-bends | sbend_off2_l80: power out 0.999894697 2e-7 | PASS | 0.99989470, expected 0.99989470, off by -4.04e-10 |
| s-bends | sbend_off2_l80: total end 0.999986122 2e-7 | PASS | 0.99998612, expected 0.99998612, off by -6.88e-11 |
| s-bends | sbend_off2_l80: centroid end 1.9999755 2e-6 | PASS | 1.99997550, expected 1.99997550, off by 4.49e-09 |
| s-bends | sbend_off2_l80: radius end 0.3051855 2e-6 | PASS | 0.30518546, expected 0.30518550, off by -4.39e-08 |
| s-bends | sbend_off2_l80: neff 2.233495224 2e-8 | PASS | 2.23349522, expected 2.23349522, off by 4.04e-10 |
| independent propagation | sbend_off4_l80: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.9e-11 of its peak |
| s-bends | sbend_off4_l80: power out 0.999815729 2e-7 | PASS | 0.99981573, expected 0.99981573, off by 4.38e-10 |
| s-bends | sbend_off4_l80: total end 0.999986412 2e-7 | PASS | 0.99998641, expected 0.99998641, off by 1.13e-10 |
| s-bends | sbend_off4_l80: centroid end 4.0003049 2e-6 | PASS | 4.00030492, expected 4.00030490, off by 1.91e-08 |
| s-bends | sbend_off4_l80: radius end 0.2995921 2e-6 | PASS | 0.29959212, expected 0.29959210, off by 1.56e-08 |
| s-bends | sbend_off4_l80: neff 2.015454774 2e-8 | PASS | 2.01545477, expected 2.01545477, off by 1.37e-11 |
| independent propagation | step_dz00625: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.8e-11 of its peak |
| step and grid | step_dz00625: power out 0.999998852 2e-7 | PASS | 0.99999885, expected 0.99999885, off by 4.85e-10 |
| step and grid | step_dz00625: neff 2.632301669 2e-8 | PASS | 2.63230167, expected 2.63230167, off by 3.73e-10 |
| step and grid | step_dz00625: neff 2.63230167 2e-6 | PASS | 2.63230167, expected 2.63230167, off by -6.27e-10 |
| step and grid | step_dz00625: power_above out 0.9995 | PASS | 0.999999 against the bound 0.999500 (margin 4.99e-04) |
| independent propagation | step_dz01250: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.5e-11 of its peak |
| step and grid | step_dz01250: power out 0.999998906 2e-7 | PASS | 0.99999891, expected 0.99999891, off by 4.35e-10 |
| step and grid | step_dz01250: neff 2.632264527 2e-8 | PASS | 2.63226453, expected 2.63226453, off by -4.44e-11 |
| step and grid | step_dz01250: neff 2.63226453 2e-6 | PASS | 2.63226453, expected 2.63226453, off by -3.04e-09 |
| step and grid | step_dz01250: power_above out 0.9995 | PASS | 0.999999 against the bound 0.999500 (margin 4.99e-04) |
| independent propagation | step_dz02500: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.6e-11 of its peak |
| step and grid | step_dz02500: power out 0.999998892 2e-7 | PASS | 0.99999889, expected 0.99999889, off by 1.65e-10 |
| step and grid | step_dz02500: neff 2.632116340 2e-8 | PASS | 2.63211634, expected 2.63211634, off by 2.24e-10 |
| step and grid | step_dz02500: neff 2.63211634 2e-6 | PASS | 2.63211634, expected 2.63211634, off by 2.24e-10 |
| step and grid | step_dz02500: power_above out 0.9995 | PASS | 0.999999 against the bound 0.999500 (margin 4.99e-04) |
| independent propagation | step_dz05000: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.5e-11 of its peak |
| step and grid | step_dz05000: power out 0.999998908 2e-7 | PASS | 0.99999891, expected 0.99999891, off by 1.71e-11 |
| step and grid | step_dz05000: neff 2.631529504 2e-8 | PASS | 2.63152950, expected 2.63152950, off by -9.10e-11 |
| step and grid | step_dz05000: neff 2.63152950 2e-6 | PASS | 2.63152950, expected 2.63152950, off by 3.91e-09 |
| step and grid | step_dz05000: power_above out 0.9995 | PASS | 0.999999 against the bound 0.999500 (margin 4.99e-04) |
| independent propagation | step_dz10000: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.0e-11 of its peak |
| step and grid | step_dz10000: power out 0.999998868 2e-7 | PASS | 0.99999887, expected 0.99999887, off by 4.68e-10 |
| step and grid | step_dz10000: neff 2.629272275 2e-8 | PASS | 2.62927228, expected 2.62927227, off by 2.26e-10 |
| step and grid | step_dz10000: neff 2.62927228 2e-6 | PASS | 2.62927228, expected 2.62927228, off by -4.77e-09 |
| step and grid | step_dz10000: power_above out 0.9995 | PASS | 0.999999 against the bound 0.999500 (margin 4.99e-04) |
| independent propagation | straight_ref1444: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.8e-11 of its peak |
| straight guides | straight_ref1444: power out 0.999998912 2e-7 | PASS | 0.99999891, expected 0.99999891, off by -4.77e-11 |
| straight guides | straight_ref1444: total end 0.999999494 2e-7 | PASS | 0.99999949, expected 0.99999949, off by 8.59e-11 |
| straight guides | straight_ref1444: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 3.19e-15 |
| straight guides | straight_ref1444: radius end 0.2753119 2e-6 | PASS | 0.27531190, expected 0.27531190, off by -2.43e-09 |
| straight guides | straight_ref1444: neff 2.830676566 2e-8 | PASS | 2.83067657, expected 2.83067657, off by 3.80e-10 |
| straight guides | straight_ref1444: neff 2.83067657 2e-6 | PASS | 2.83067657, expected 2.83067657, off by -3.62e-09 |
| straight guides | straight_ref1444: power_above out 0.9995 | PASS | 0.999999 against the bound 0.999500 (margin 4.99e-04) |
| independent propagation | straight_ref2000: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.6e-11 of its peak |
| straight guides | straight_ref2000: power out 0.999998880 2e-7 | PASS | 0.99999888, expected 0.99999888, off by 3.84e-10 |
| straight guides | straight_ref2000: total end 0.999999499 2e-7 | PASS | 0.99999950, expected 0.99999950, off by 4.68e-10 |
| straight guides | straight_ref2000: centroid end -0.0000000 2e-6 | PASS | 0.00000000, expected -0.00000000, off by 2.26e-15 |
| straight guides | straight_ref2000: radius end 0.2753094 2e-6 | PASS | 0.27530938, expected 0.27530940, off by -2.06e-08 |
| straight guides | straight_ref2000: neff 2.697343432 2e-8 | PASS | 2.69734343, expected 2.69734343, off by -4.77e-10 |
| straight guides | straight_ref2000: neff 2.69734343 2e-6 | PASS | 2.69734343, expected 2.69734343, off by 1.52e-09 |
| straight guides | straight_ref2000: power_above out 0.9995 | PASS | 0.999999 against the bound 0.999500 (margin 4.99e-04) |
| independent propagation | straight_ref3200: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.8e-11 of its peak |
| straight guides | straight_ref3200: power out 0.999998876 2e-7 | PASS | 0.99999888, expected 0.99999888, off by 2.37e-10 |
| straight guides | straight_ref3200: total end 0.999999541 2e-7 | PASS | 0.99999954, expected 0.99999954, off by 1.54e-10 |
| straight guides | straight_ref3200: centroid end -0.0000000 2e-6 | PASS | -0.00000000, expected -0.00000000, off by -1.23e-16 |
| straight guides | straight_ref3200: radius end 0.2753097 2e-6 | PASS | 0.27530972, expected 0.27530970, off by 2.48e-08 |
| straight guides | straight_ref3200: neff 2.691493391 2e-8 | PASS | 2.69149339, expected 2.69149339, off by 3.82e-11 |
| straight guides | straight_ref3200: neff 2.69149339 2e-6 | PASS | 2.69149339, expected 2.69149339, off by 1.04e-09 |
| straight guides | straight_ref3200: power_above out 0.9995 | PASS | 0.999999 against the bound 0.999500 (margin 4.99e-04) |
| independent propagation | straight_w0400_m0: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.4e-11 of its peak |
| solution without stepping | straight_w0400_m0: output field against the modal solution of the same grid | PASS | largest difference 3.4e-04 of the peak (bound 0.002) |
| straight guides | straight_w0400_m0: power out 0.999998087 2e-7 | PASS | 0.99999809, expected 0.99999809, off by -4.61e-10 |
| straight guides | straight_w0400_m0: total end 0.999999621 2e-7 | PASS | 0.99999962, expected 0.99999962, off by -2.18e-10 |
| straight guides | straight_w0400_m0: centroid end -0.0000000 2e-6 | PASS | -0.00000000, expected -0.00000000, off by -2.34e-15 |
| straight guides | straight_w0400_m0: radius end 0.2488348 2e-6 | PASS | 0.24883479, expected 0.24883480, off by -1.30e-08 |
| straight guides | straight_w0400_m0: neff 2.551179397 2e-8 | PASS | 2.55117940, expected 2.55117940, off by -1.25e-10 |
| straight guides | straight_w0400_m0: neff 2.55117940 2e-6 | PASS | 2.55117940, expected 2.55117940, off by -3.12e-09 |
| straight guides | straight_w0400_m0: power_above out 0.9995 | PASS | 0.999998 against the bound 0.999500 (margin 4.98e-04) |
| independent propagation | straight_w0500_m0: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.7e-11 of its peak |
| solution without stepping | straight_w0500_m0: output field against the modal solution of the same grid | PASS | largest difference 9.7e-05 of the peak (bound 0.002) |
| straight guides | straight_w0500_m0: power out 0.999998856 2e-7 | PASS | 0.99999886, expected 0.99999886, off by -2.66e-10 |
| straight guides | straight_w0500_m0: total end 0.999999514 2e-7 | PASS | 0.99999951, expected 0.99999951, off by 2.22e-10 |
| straight guides | straight_w0500_m0: centroid end -0.0000000 2e-6 | PASS | -0.00000000, expected -0.00000000, off by -1.09e-16 |
| straight guides | straight_w0500_m0: radius end 0.2753074 2e-6 | PASS | 0.27530738, expected 0.27530740, off by -1.63e-08 |
| straight guides | straight_w0500_m0: neff 2.628986590 2e-8 | PASS | 2.62898659, expected 2.62898659, off by 4.15e-10 |
| straight guides | straight_w0500_m0: neff 2.62898659 2e-6 | PASS | 2.62898659, expected 2.62898659, off by 4.15e-10 |
| straight guides | straight_w0500_m0: power_above out 0.9995 | PASS | 0.999999 against the bound 0.999500 (margin 4.99e-04) |
| independent propagation | straight_w0800_m0: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.8e-11 of its peak |
| solution without stepping | straight_w0800_m0: output field against the modal solution of the same grid | PASS | largest difference 7.2e-04 of the peak (bound 0.002) |
| straight guides | straight_w0800_m0: power out 0.999999554 2e-7 | PASS | 0.99999955, expected 0.99999955, off by 8.71e-11 |
| straight guides | straight_w0800_m0: total end 0.999999926 2e-7 | PASS | 0.99999993, expected 0.99999993, off by -2.32e-10 |
| straight guides | straight_w0800_m0: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 2.28e-15 |
| straight guides | straight_w0800_m0: radius end 0.3719149 2e-6 | PASS | 0.37191490, expected 0.37191490, off by 2.86e-09 |
| straight guides | straight_w0800_m0: neff 2.741724540 2e-8 | PASS | 2.74172454, expected 2.74172454, off by -2.79e-10 |
| straight guides | straight_w0800_m0: neff 2.74172454 2e-6 | PASS | 2.74172454, expected 2.74172454, off by -2.79e-10 |
| straight guides | straight_w0800_m0: power_above out 0.9995 | PASS | 1.000000 against the bound 0.999500 (margin 5.00e-04) |
| independent propagation | straight_w1200_m0: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.5e-11 of its peak |
| straight guides | straight_w1200_m0: power out 0.999999830 2e-7 | PASS | 0.99999983, expected 0.99999983, off by 3.48e-10 |
| straight guides | straight_w1200_m0: total end 0.999999972 2e-7 | PASS | 0.99999997, expected 0.99999997, off by -3.19e-10 |
| straight guides | straight_w1200_m0: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 2.06e-15 |
| straight guides | straight_w1200_m0: radius end 0.5114102 2e-6 | PASS | 0.51141023, expected 0.51141020, off by 2.84e-08 |
| straight guides | straight_w1200_m0: neff 2.793978285 2e-8 | PASS | 2.79397828, expected 2.79397829, off by -1.98e-10 |
| straight guides | straight_w1200_m0: neff 2.79397828 2e-6 | PASS | 2.79397828, expected 2.79397828, off by 4.80e-09 |
| straight guides | straight_w1200_m0: power_above out 0.9995 | PASS | 1.000000 against the bound 0.999500 (margin 5.00e-04) |
| independent propagation | straight_w1200_m1: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 4.1e-11 of its peak |
| solution without stepping | straight_w1200_m1: output field against the modal solution of the same grid | PASS | largest difference 9.6e-04 of the peak (bound 0.002) |
| straight guides | straight_w1200_m1: power out 0.999999179 2e-7 | PASS | 0.99999918, expected 0.99999918, off by -2.64e-10 |
| straight guides | straight_w1200_m1: total end 0.999999873 2e-7 | PASS | 0.99999987, expected 0.99999987, off by 5.55e-11 |
| straight guides | straight_w1200_m1: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 8.02e-17 |
| straight guides | straight_w1200_m1: radius end 0.7601015 2e-6 | PASS | 0.76010154, expected 0.76010150, off by 4.03e-08 |
| straight guides | straight_w1200_m1: neff 2.627189252 2e-8 | PASS | 2.62718925, expected 2.62718925, off by -1.64e-10 |
| straight guides | straight_w1200_m1: neff 2.62718925 2e-6 | PASS | 2.62718925, expected 2.62718925, off by 1.84e-09 |
| straight guides | straight_w1200_m1: power_above out 0.9995 | PASS | 0.999999 against the bound 0.999500 (margin 4.99e-04) |
| independent propagation | straight_w2000_m1: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 5.7e-12 of its peak |
| straight guides | straight_w2000_m1: power out 0.999999806 2e-7 | PASS | 0.99999981, expected 0.99999981, off by -3.79e-11 |
| straight guides | straight_w2000_m1: total end 0.999999973 2e-7 | PASS | 0.99999997, expected 0.99999997, off by 3.12e-10 |
| straight guides | straight_w2000_m1: centroid end 0.0000000 2e-6 | PASS | -0.00000000, expected 0.00000000, off by -1.02e-14 |
| straight guides | straight_w2000_m1: radius end 1.1757582 2e-6 | PASS | 1.17575818, expected 1.17575820, off by -2.01e-08 |
| straight guides | straight_w2000_m1: neff 2.759890656 2e-8 | PASS | 2.75989066, expected 2.75989066, off by 4.78e-10 |
| straight guides | straight_w2000_m1: neff 2.75989066 2e-6 | PASS | 2.75989066, expected 2.75989066, off by -3.52e-09 |
| straight guides | straight_w2000_m1: power_above out 0.9995 | PASS | 1.000000 against the bound 0.999500 (margin 5.00e-04) |
| independent propagation | straight_w2000_m2: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 6.7e-12 of its peak |
| solution without stepping | straight_w2000_m2: output field against the modal solution of the same grid | PASS | largest difference 9.5e-04 of the peak (bound 0.002) |
| straight guides | straight_w2000_m2: power out 0.999999187 2e-7 | PASS | 0.99999919, expected 0.99999919, off by 2.34e-10 |
| straight guides | straight_w2000_m2: total end 0.999999924 2e-7 | PASS | 0.99999992, expected 0.99999992, off by -7.54e-11 |
| straight guides | straight_w2000_m2: centroid end -0.0000000 2e-6 | PASS | 0.00000000, expected -0.00000000, off by 7.94e-15 |
| straight guides | straight_w2000_m2: radius end 1.2403027 2e-6 | PASS | 1.24030272, expected 1.24030270, off by 1.86e-08 |
| straight guides | straight_w2000_m2: neff 2.646420989 2e-8 | PASS | 2.64642099, expected 2.64642099, off by -1.07e-10 |
| straight guides | straight_w2000_m2: neff 2.64642099 2e-6 | PASS | 2.64642099, expected 2.64642099, off by -1.11e-09 |
| straight guides | straight_w2000_m2: power_above out 0.9995 | PASS | 0.999999 against the bound 0.999500 (margin 4.99e-04) |
| independent propagation | taper_down_l10: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.7e-11 of its peak |
| tapers | taper_down_l10: power out 0.976108618 2e-7 | PASS | 0.97610862, expected 0.97610862, off by -3.96e-10 |
| tapers | taper_down_l10: total end 0.999999899 2e-7 | PASS | 0.99999990, expected 0.99999990, off by 1.82e-10 |
| tapers | taper_down_l10: centroid end -0.0000000 2e-6 | PASS | 0.00000000, expected -0.00000000, off by 2.17e-15 |
| tapers | taper_down_l10: radius end 1.0315306 2e-6 | PASS | 1.03153062, expected 1.03153060, off by 1.86e-08 |
| tapers | taper_down_l10: neff 2.757983106 2e-8 | PASS | 2.75798311, expected 2.75798311, off by 6.52e-11 |
| independent propagation | taper_down_l40: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 3.9e-11 of its peak |
| tapers | taper_down_l40: power out 0.997663821 2e-7 | PASS | 0.99766382, expected 0.99766382, off by -1.98e-10 |
| tapers | taper_down_l40: total end 0.999997755 2e-7 | PASS | 0.99999776, expected 0.99999775, off by 4.82e-10 |
| tapers | taper_down_l40: centroid end 0.0000000 2e-6 | PASS | -0.00000000, expected 0.00000000, off by -5.76e-15 |
| tapers | taper_down_l40: radius end 0.3946137 2e-6 | PASS | 0.39461365, expected 0.39461370, off by -4.84e-08 |
| tapers | taper_down_l40: neff 2.779526553 2e-8 | PASS | 2.77952655, expected 2.77952655, off by -6.27e-11 |
| independent propagation | taper_down_l80: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 2.6e-11 of its peak |
| tapers | taper_down_l80: power out 0.999519974 2e-7 | PASS | 0.99951997, expected 0.99951997, off by -4.26e-10 |
| tapers | taper_down_l80: total end 0.999994830 2e-7 | PASS | 0.99999483, expected 0.99999483, off by 7.26e-11 |
| tapers | taper_down_l80: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 5.74e-15 |
| tapers | taper_down_l80: radius end 0.3132194 2e-6 | PASS | 0.31321937, expected 0.31321940, off by -2.56e-08 |
| tapers | taper_down_l80: neff 2.788192308 2e-8 | PASS | 2.78819231, expected 2.78819231, off by 3.61e-10 |
| independent propagation | taper_up_l05: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 8.5e-12 of its peak |
| tapers | taper_up_l05: power out 0.931416961 2e-7 | PASS | 0.93141696, expected 0.93141696, off by -1.45e-10 |
| tapers | taper_up_l05: total end 0.999999878 2e-7 | PASS | 0.99999988, expected 0.99999988, off by -1.10e-10 |
| tapers | taper_up_l05: centroid end 0.0000000 2e-6 | PASS | -0.00000000, expected 0.00000000, off by -1.36e-14 |
| tapers | taper_up_l05: radius end 1.2683450 2e-6 | PASS | 1.26834504, expected 1.26834500, off by 3.68e-08 |
| tapers | taper_up_l05: neff 2.752431177 2e-8 | PASS | 2.75243118, expected 2.75243118, off by -3.18e-10 |
| independent propagation | taper_up_l10: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 9.0e-12 of its peak |
| tapers | taper_up_l10: power out 0.976108618 2e-7 | PASS | 0.97610862, expected 0.97610862, off by -3.96e-10 |
| tapers | taper_up_l10: total end 0.999999058 2e-7 | PASS | 0.99999906, expected 0.99999906, off by 7.80e-11 |
| tapers | taper_up_l10: centroid end 0.0000000 2e-6 | PASS | -0.00000000, expected 0.00000000, off by -1.58e-14 |
| tapers | taper_up_l10: radius end 1.2160789 2e-6 | PASS | 1.21607889, expected 1.21607890, off by -5.04e-09 |
| tapers | taper_up_l10: neff 2.759156471 2e-8 | PASS | 2.75915647, expected 2.75915647, off by -8.07e-11 |
| independent propagation | taper_up_l20: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 8.9e-12 of its peak |
| tapers | taper_up_l20: power out 0.991000039 2e-7 | PASS | 0.99100004, expected 0.99100004, off by 2.86e-10 |
| tapers | taper_up_l20: total end 0.999950250 2e-7 | PASS | 0.99995025, expected 0.99995025, off by 4.17e-10 |
| tapers | taper_up_l20: centroid end 0.0000000 2e-6 | PASS | -0.00000000, expected 0.00000000, off by -2.21e-14 |
| tapers | taper_up_l20: radius end 1.1671344 2e-6 | PASS | 1.16713441, expected 1.16713440, off by 6.12e-09 |
| tapers | taper_up_l20: neff 2.769133761 2e-8 | PASS | 2.76913376, expected 2.76913376, off by -3.07e-10 |
| independent propagation | taper_up_l40: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 8.7e-12 of its peak |
| tapers | taper_up_l40: power out 0.997663821 2e-7 | PASS | 0.99766382, expected 0.99766382, off by -1.98e-10 |
| tapers | taper_up_l40: total end 0.999955678 2e-7 | PASS | 0.99995568, expected 0.99995568, off by 1.62e-10 |
| tapers | taper_up_l40: centroid end 0.0000000 2e-6 | PASS | -0.00000000, expected 0.00000000, off by -1.89e-14 |
| tapers | taper_up_l40: radius end 1.1401597 2e-6 | PASS | 1.14015969, expected 1.14015970, off by -5.93e-09 |
| tapers | taper_up_l40: neff 2.779621697 2e-8 | PASS | 2.77962170, expected 2.77962170, off by 3.21e-10 |
| independent propagation | taper_up_l80: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 8.1e-12 of its peak |
| tapers | taper_up_l80: power out 0.999519974 2e-7 | PASS | 0.99951997, expected 0.99951997, off by -4.26e-10 |
| tapers | taper_up_l80: total end 0.999964503 2e-7 | PASS | 0.99996450, expected 0.99996450, off by -2.83e-10 |
| tapers | taper_up_l80: centroid end 0.0000000 2e-6 | PASS | -0.00000000, expected 0.00000000, off by -3.09e-14 |
| tapers | taper_up_l80: radius end 1.1531133 2e-6 | PASS | 1.15311333, expected 1.15311330, off by 2.87e-08 |
| tapers | taper_up_l80: neff 2.788234832 2e-8 | PASS | 2.78823483, expected 2.78823483, off by -4.20e-10 |
| independent propagation | ybranch_l10: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 5.6e-12 of its peak |
| y-branches | ybranch_l10: power upper 0.495261588 2e-7 | PASS | 0.49526159, expected 0.49526159, off by 2.56e-10 |
| y-branches | ybranch_l10: power lower 0.495261588 2e-7 | PASS | 0.49526159, expected 0.49526159, off by 2.56e-10 |
| y-branches | ybranch_l10: total end 0.999990561 2e-7 | PASS | 0.99999056, expected 0.99999056, off by 4.19e-10 |
| y-branches | ybranch_l10: centroid end -0.0000000 2e-6 | PASS | -0.00000000, expected -0.00000000, off by -1.68e-14 |
| y-branches | ybranch_l10: radius end 2.9677403 2e-6 | PASS | 2.96774033, expected 2.96774030, off by 3.25e-08 |
| y-branches | ybranch_l10: neff 2.339423758 2e-8 | PASS | 2.33942376, expected 2.33942376, off by -4.12e-10 |
| y-branches | ybranch_l10: ratio upper lower 1.0 1e-6 | PASS | 1.00000000, expected 1.00000000, off by -2.43e-14 |
| independent propagation | ybranch_l20: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 5.4e-12 of its peak |
| y-branches | ybranch_l20: power upper 0.499711653 2e-7 | PASS | 0.49971165, expected 0.49971165, off by -4.13e-10 |
| y-branches | ybranch_l20: power lower 0.499711653 2e-7 | PASS | 0.49971165, expected 0.49971165, off by -4.13e-10 |
| y-branches | ybranch_l20: total end 0.999976308 2e-7 | PASS | 0.99997631, expected 0.99997631, off by 3.43e-10 |
| y-branches | ybranch_l20: centroid end -0.0000000 2e-6 | PASS | 0.00000000, expected -0.00000000, off by 4.06e-15 |
| y-branches | ybranch_l20: radius end 3.0258901 2e-6 | PASS | 3.02589014, expected 3.02589010, off by 4.07e-08 |
| y-branches | ybranch_l20: neff 2.377848497 2e-8 | PASS | 2.37784850, expected 2.37784850, off by 2.66e-10 |
| y-branches | ybranch_l20: ratio upper lower 1.0 1e-6 | PASS | 1.00000000, expected 1.00000000, off by 6.88e-15 |
| independent propagation | ybranch_l40: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 4.0e-11 of its peak |
| y-branches | ybranch_l40: power upper 0.499853493 2e-7 | PASS | 0.49985349, expected 0.49985349, off by -4.08e-10 |
| y-branches | ybranch_l40: power lower 0.499853493 2e-7 | PASS | 0.49985349, expected 0.49985349, off by -4.08e-10 |
| y-branches | ybranch_l40: total end 0.999965082 2e-7 | PASS | 0.99996508, expected 0.99996508, off by 1.90e-11 |
| y-branches | ybranch_l40: centroid end 0.0000000 2e-6 | PASS | 0.00000000, expected 0.00000000, off by 1.52e-14 |
| y-branches | ybranch_l40: radius end 3.0060238 2e-6 | PASS | 3.00602380, expected 3.00602380, off by 1.13e-09 |
| y-branches | ybranch_l40: neff 2.428390414 2e-8 | PASS | 2.42839041, expected 2.42839041, off by -2.73e-10 |
| y-branches | ybranch_l40: ratio upper lower 1.0 1e-6 | PASS | 1.00000000, expected 1.00000000, off by 2.11e-14 |
| independent propagation | ybranch_l80: monitors, planes, index and output field stepped again in NumPy | PASS | output field within 4.2e-11 of its peak |
| y-branches | ybranch_l80: power upper 0.499830658 2e-7 | PASS | 0.49983066, expected 0.49983066, off by 8.24e-11 |
| y-branches | ybranch_l80: power lower 0.499830658 2e-7 | PASS | 0.49983066, expected 0.49983066, off by 8.24e-11 |
| y-branches | ybranch_l80: total end 0.999916699 2e-7 | PASS | 0.99991670, expected 0.99991670, off by 3.41e-10 |
| y-branches | ybranch_l80: centroid end -0.0000000 2e-6 | PASS | -0.00000000, expected -0.00000000, off by -1.28e-14 |
| y-branches | ybranch_l80: radius end 3.0084062 2e-6 | PASS | 3.00840621, expected 3.00840620, off by 9.73e-09 |
| y-branches | ybranch_l80: neff 2.378551238 2e-8 | PASS | 2.37855124, expected 2.37855124, off by -1.50e-10 |
| y-branches | ybranch_l80: ratio upper lower 1.0 1e-6 | PASS | 1.00000000, expected 1.00000000, off by -1.39e-14 |
| step size | the error of the output field falls as the square of the step | PASS | fitted order 1.97 over 5 step sizes |
| adiabatic transitions | Taper 0.5 to 3 um: transmission does not fall as the transition gets longer | PASS | 0.9314, 0.9761, 0.9910, 0.9977, 0.9995 |
| adiabatic transitions | Taper 3 to 0.5 um: transmission does not fall as the transition gets longer | PASS | 0.9761, 0.9977, 0.9995 |
| adiabatic transitions | S-bend, 1 um offset: transmission does not fall as the transition gets longer | PASS | 0.9981, 0.9999, 0.9999 |
| adiabatic transitions | S-bend, 2 um offset: transmission does not fall as the transition gets longer | PASS | 0.9997, 0.9999, 0.9999 |
| reciprocity | a taper and its mirror image transmit the same, mode to mode | PASS | largest difference 0.0e+00 over 3 lengths |
| couplers | the launch guide empties at the coupling length predicted from the supermodes | PASS | largest deviation 1.6% over 5 gaps |
| multimode interference | each 1x2 interferometer is best at the imaging length 3 L_pi / 8 | PASS | 4 um wide: 0.493 per output, 6 um wide: 0.492 per output, 8 um wide: 0.490 per output |
