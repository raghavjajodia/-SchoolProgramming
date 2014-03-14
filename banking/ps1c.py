#Problem Set 1C
#Name: Niki Castle
#Collaborators: none
#Time Spent: ~1hr

balance = float(raw_input('Enter the outstanding balance on your credit card: '))
interest = float(raw_input('Enter the annual credit card interest rate as a decimal: '))
minPay = balance/12.0
maxPay = (balance*(1+(interest/12.0))*12.0)/12.0
newBalance = balance

#Find the lowest monthly payment using bisection search.
#Payment is in interval (minPay,maxPay).
#If final balance > 0, test upper half of interval.
#If final balance < 0, test lower half of interval.

while balance > 0:
    payment = (minPay+maxPay)/2.0
    for month in range(1,13):
        newBalance = round((newBalance*(1+(interest/12))-(payment)),2)
        if newBalance <=0:
            break
    if newBalance == 0.0:
        balance = newBalance
    elif newBalance > 0.0: 
        newBalance = balance
        minPay = payment
    else:
        newBalance = balance
        maxPay = payment

print 'RESULT'
print 'Monthly payment to pay off debt in 1 year: ' + str(round(minPay,2))
print 'Number of months needed: ' + str(month)
print 'Balance: ' + str(round(balance,2))
