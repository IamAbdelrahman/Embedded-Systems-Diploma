import datetime as dt
t = dt.datetime.now()
# t now equals the current date

print("Enter your number1: ")
# num1 = int (input (":"))
print("Enter your number2: ")
# num2 = int(input (":"))
num1 = 1
num2 = 2
sum = num1 + num2
print(f"sum is", sum)
# Final time - Initial time
t = dt.datetime.now() - t
# Display the difference in seconds
print(t.microseconds)

