# Классы и наследование

  Сотрудники института биоинформатики хотят восстановить первичную структуру белка,
для чего требуется объединить его (частично пересекающиеся) фрагменты. Требуется написать программу (с интерфейсом), 
которая хранит белковые последовательности (в виде списков аминокислот) и умеет их объединять, 
если аминокислоты в конце одной последовательности совпадут с аминокислотами в начале другой.

1. Протеиногенная аминокислота: способ показывать (и принимать) своё полное название
и однобуквенное обозначение
2. Белок (двусвязный список аминокислот): операция сложения, возвращающая результат
сложения (с пересечением) двух белков
3. Нестандартная аминокислота: способ показывать и принимать своё полное название
