#Problem Set 1B
#Name: Niki Castle
#Collaborators: none
#Time Spent: <1hr

#Get current balance and interest rate; set payment at $10/month and
#make a placeholder for balance.

balance = float(raw_input('Enter the outstanding balance on your credit card: '))
interest = float(raw_input('Enter the annual credit card interest rate as a decimal: '))
minPay = 10
newBalance = balance

#Calculate balance left by paying $minPay each month for 12 (or fewer) months.
#Add $10 to minPay and repeat until balance goes to 0 or less.

while balance > 0:
    for month in range(1,13):
        newBalance = newBalance*(1+(interest/12))-minPay
        if newBalance <=0:
            break
    if newBalance <= 0:
        balance = newBalance
    else:
        newBalance = balance
        minPay = minPay+10
    

print 'RESULT'
print 'Monthly payment to pay off debt in 1 year: ' + str(minPay)
print 'Number of months needed: ' + str(month)
print 'Balance: ' + str(round(balance,2))
