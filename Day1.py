import math

nums = """109067
75007
66030
93682
83818
108891
139958
129246
80272
119897
112804
69495
95884
85402
148361
75986
120063
127683
146962
76907
61414
98452
134330
53858
82662
143258
82801
60279
131782
105989
102464
96563
71172
113731
90645
94830
133247
110149
54792
134863
125919
145490
69836
108808
87954
148957
110182
126668
148024
96915
117727
147378
75967
91915
60130
85331
66800
103419
72627
72687
61606
113160
107082
110793
61589
105005
73952
65705
117243
140944
117091
113482
91379
148185
113853
119822
78179
85407
119886
109230
68783
63914
51101
93549
53361
127984
106315
54997
138941
81075
120272
120307
98414
115245
105649
89793
88421
121104
97084
56928"""

module_fuel = nums.split("\n")

def fueling(weights):
    tot_fuel = 0
    for each in weights:
        x = int(each)
        math_stuff = math.floor(x / 3) - 2
        tot_fuel += math_stuff
        fuel_weight = math_stuff
        # The above'll getcha the first answer (how much fuel for weight, not counting additional fuel) 
        # -- below for the second (how much once fuel is added to the weight).
        while fuel_weight > 0:
            fuel_calc = math.floor(fuel_weight / 3) - 2
            # print(f'Weight: {fuel_weight} :: Calc: {fuel_calc}') ## debug print

            if fuel_calc > 0:
                fuel_weight = fuel_calc
                tot_fuel += fuel_calc
            else:
                fuel_weight = 0

fueling(module_fuel)
