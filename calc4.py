def restaurant():
    menu = {"pizza": 700, "sushi": 500, "burger": 350, "fries": 250}
    
    while True:
        dish_input = input("\nDish (or 'exit'): ").lower()
        
        if dish_input == "exit":
            print("Goodbye,thanks!")
            break
            
        dish = dish_input.split()[0] if dish_input else ""
            
        if dish not in menu:
            print("Not on the menu")
            continue
            
        count = int(input("Portions: "))
        people = int(input("People: "))
        
        total = menu[dish] * count * 1.1
        per_person = round(total / people, 2)
        
        print("Total:", total, "rub.")
        print("Per person:", per_person, "rub.")

restaurant()