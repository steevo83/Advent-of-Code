with open('Calibration document.txt') as f:
    alllines = []
    for line in f.readlines():
        nums = []
        for char in line:
            if char.isnumeric():
                nums.append(char)
        #print(nums)
        linetot = nums[0]+nums[-1]
        #print(linetot)
        alllines.append(linetot)
    allnums = [int(x) for x in alllines]
    alltot = sum(allnums)
    print(alltot)
