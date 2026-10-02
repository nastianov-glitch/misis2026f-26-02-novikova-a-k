def level_1():
    print(' Уровень 1: upper, lower, capitalize ')
    print('lower      - нижний регистр')
    print('upper      - верхний регистр')
    print('capitalize - первая буква заглавная, остальные строчные')
    print('Пример для "привет - мир":')
    print('  capitalize - "Привет - Мир"')
    print('  lower      - "привет - мир"')
    print('  upper      - "ПРИВЕТ - МИР"')

    while True:
        method = input('\nВведите метод (или 6 для выхода): ')
        if method == '6':
            return
        if method in ('upper', 'lower', 'capitalize'):
            word = input('Введите слово: ')
            print('Результат:', getattr(word, method)())
        else:
            print('Неизвестный метод. Доступны: upper, lower, capitalize')

def level_2():
    print(' Уровень 2: find, replace, count, index ')
    print('find    - индекс первого вхождения подстроки, или -1, если не найдена')
    print('replace - заменяет подстроку на другую')
    print('count   - количество вхождений подстроки')
    print('index   - как find, но бросает ValueError, если подстрока не найдена')
    print('Пример для "Ботать это круто. Очень круто":')
    print('  find("круто")             - индекс первого "круто"')
    print('  replace("круто", "мощно") - "Ботать это мощно. Очень мощно"')
    print('  count("круто")            - 2')
    print('  index("круто")            - индекс первого "круто"')

    while True:
        method = input('\nВведите метод (или 6 для выхода): ')
        if method == '6':
            return

        if method == 'find':
            word = input('Введите слово: ')
            sub = input('Введите подстроку: ')
            print('Результат:', word.find(sub))

        elif method == 'replace':
            word = input('Введите слово: ')
            sub = input('Что заменить: ')
            new = input('На что заменить: ')
            print('Результат:', word.replace(sub, new))

        elif method == 'count':
            word = input('Введите слово: ')
            sub = input('Введите подстроку: ')
            print('Результат:', word.count(sub))

        elif method == 'index':
            word = input('Введите слово: ')
            sub = input('Введите подстроку: ')
            try:
                print('Результат:', word.index(sub))
            except ValueError:
                print('Подстрока не найдена (ValueError)')

        else:
            print('Неизвестный метод. Доступны: find, replace, count, index')

def level_3():
    print(' Уровень 3: split, join ')
    print('split - разбивает строку на список подстрок по разделителю')
    print('join  - склеивает список строк в одну строку через разделитель')
    print('Пример для "Ботать это круто. Очень круто":')
    print('  split(" ")            - ["Ботать", "это", "круто.", "Очень", "круто"]')
    print('  ", ".join([...])      - "Ботать, это, круто., Очень, круто"')

    while True:
        method = input('\nВведите метод (или Exit для выхода): ').strip()
        if method == '6':
            return

        if method == 'split':
            word = input('Введите слово: ')
            sep = input('Введите разделитель (Enter = пробел): ') or ' '
            print('Результат:', word.split(sep))

        elif method == 'join':
            word = input('Введите слово: ')
            sep = input('Введите разделитель (Enter = пробел): ') or ' '
            print('Результат:', sep.join(word.split()))

        else:
            print('Неизвестный метод. Доступны: split, join')

def level_4():
    print('Уровень 4: isdigit, isalpha, strip, format, [::-1], lower, upper ')
    print('isdigit   - состоит ли строка только из цифр')
    print('isalpha   - состоит ли строка только из букв')
    print('strip     - убирает пробелы в начале и конце')
    print('format    - форматирование строки')
    print('[::-1]    - срез, разворачивает строку (НЕ метод)')
    print('lower     - нижний регистр')
    print('upper     - верхний регистр')
    print('Пример: "1234*&^%"')
    print('  isdigit()  -> False (есть не только цифры)')
    print('  isalpha()  -> False (есть не только буквы)')

    while True:
        method = input('\nВведите метод (или 6 для выхода): ')
        if method == '6':
            return

        if method == 'isdigit':
            word = input('Введите слово: ')
            print('Результат:', word.isdigit())

        elif method == 'isalpha':
            word = input('Введите слово: ')
            print('Результат:', word.isalpha())

        elif method == 'strip':
            word = input('Введите слово с пробелами по краям: ')
            print('Результат:', repr(word.strip()))

        elif method == 'format':
            word = input('Введите число: ')
            try:
                print('Результат:', '{:.2f}'.format(float(word)))
            except ValueError:
                print('Это не число.')

        elif method == 'reverse':
            word = input('Введите слово: ')
            print('Результат:', word[::-1])

        elif method == 'lower':
            word = input('Введите слово: ')
            print('Результат:', word.lower())

        elif method == 'upper':
            word = input('Введите слово: ')
            print('Результат:', word.upper())

        else:
            print('Неизвестный метод. Доступны: isdigit, isalpha, strip, '
                  'format, reverse, lower, upper')

def level_5():
    print(' Уровень 5: секретный ')
    print('Цепочка методов: strip -> replace -> upper -> capitalize')
    result = '   python;is;AWESOME   '.strip().replace(';', ' ').upper().capitalize()
    print('Исходная строка :', repr('   python;is;AWESOME   '))
    print('Результат       :', repr(result))
    print('Разбор:')
    print('  strip()          убирает пробелы по краям - "python;is;AWESOME"')
    print('  replace(";", " ") меняет ; на пробел     - "python is AWESOME"')
    print('  upper()          верхний регистр         - "PYTHON IS AWESOME"')
    print('  capitalize()     первая заглавная, ост. строчные - "Python is awesome"')

def main():
    levels = {
        '1': level_1,
        '2': level_2,
        '3': level_3,
        '4': level_4,
        '5': level_5,
    }

    while True:
        choice = input('Введите номер уровня (1-5) или 6 для выхода: ').strip()

        if choice == '6':
            print('До встречи!')
            break

        if choice in levels:
            levels[choice]()
        else:
            print('Такого уровня нет. Попробуйте 1-5.')

if __name__ == '__main__':
    main()