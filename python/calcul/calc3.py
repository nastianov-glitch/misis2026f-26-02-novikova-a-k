def restaurant():
    menu = {"pizza": 700, "sushi": 500, "burger": 350, "fries": 250}
    
    dish_input = input("Dish (pizza/sushi/burger/fries): ").lower()
    dish = dish_input.split()[0] if dish_input else ""
    
    if dish not in menu:
        print("Not on the menu")
        return
        
    count = int(input("Portions: "))
    people = int(input("People: "))
    
    total = menu[dish] * count * 1.1  # +10% чаевые
    per_person = round(total / people, 2)
    
    print("Total:", total, "rub.")
    print("Per person:", per_person, "rub.")

restaurant()