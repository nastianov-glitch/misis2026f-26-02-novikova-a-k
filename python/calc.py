print("=== Калькулятор счёта в ресторане ===")
dish = input("Что заказали? (пицца/суши/бургер/картофель фри): ").lower()
count = int(input("Сколько порций? "))
people = int(input("На сколько человек делим? "))

if dish == "пицца":
    price = 700
elif dish == "суши":
    price = 500
elif dish == "бургер":
    price = 350
elif dish == "картофель фри":
    price = 250
else:
    price = 0
    print("Такого блюда нет в меню")

total = price * count
tips = total * 0.1
final = total + tips
print(f"Итого: {final} руб. ({final / people:.2f} руб. с человека)")