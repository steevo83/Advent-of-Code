replacements = [("one","one1one"),("two","two2two"),("three","three3three"),("four","four4four"),("five","five5five"),("six","six6six"),("seven","seven7seven"),("eight","eight8eight"),("nine","nine9nine")]
with open('Calibration document.txt') as f:
    alllines = []
    for line in f.readlines():
        for old, new in replacements:
            line = line.replace(old, new)
        nums = []
        [nums.append(char) for char in line if char.isnumeric()]
        linetot = nums[0]+nums[-1]
        alllines.append(linetot)
    allnums = [int(x) for x in alllines]
    alltot = sum(allnums)
    print(alltot)
