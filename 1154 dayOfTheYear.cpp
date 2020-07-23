class Solution:
    def dayOfYear(self, date: str) -> int:
        monthToDay =[31,28,31,30,31,30,31,31,30,31,30,31]
        dateAnalysis = date.split('-')
        monthAnalysis =  dateAnalysis[1]
        dayAnalysis = dateAnalysis[2]
        year = dateAnalysis[0]
        year = int(year)
        # print(year)
        month = ""
        day = ""
        for char in monthAnalysis:
            if char == '0':
                if month == "":
                    continue

            month += char
        for char in dayAnalysis:
            if char == '0':
                if day == "":
                    continue

            day += char
        # print(month)
        # print(day)
        month = int(month)
        day = int(day)
        if month == 1:
            return day
        else:
            if month > 2:
                if (year % 100 != 0 and year % 4 == 0) or year % 400 == 0:
                    day = day + 1
                    # print(day)

            i = 0
            res = 0
            while i <= month - 2:
                res += monthToDay[i]
                i += 1
            res += day
            return res