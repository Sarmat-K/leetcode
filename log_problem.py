import os
from datetime import datetime

# Функция для создания папки с датой, если она не существует
def create_date_folder():
    today = datetime.now().strftime('%m.%d.%Y')  # Формат папки: ММ.ДД.ГГГГ
    if not os.path.exists(today):
        os.makedirs(today)
    return today

# Функция для записи задачи в файл
def log_problem(problem_number, problem_name, difficulty, topics):
    folder = create_date_folder()
    file_name = f"{problem_number}_{problem_name.replace(' ', '_')}.cpp"
    file_path = os.path.join(folder, file_name)
    
    # Создаем файл с задачей, если он не существует
    if not os.path.exists(file_path):
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(f"// Solution for problem {problem_number}: {problem_name}\n")
            f.write(f"// Difficulty: {difficulty}\n")
            f.write(f"// Topics: {topics}\n\n")
            f.write("// Your solution code goes here.\n\n")
            f.write("#include <iostream>\n#include <unordered_map>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n") # добоавляю библиотеки для работы !
        print(f"Файл '{file_name}' успешно создан в папке '{folder}'.")
    else:
        print(f"Файл '{file_name}' уже существует.")
    
    # Обновляем README с новой задачей
    update_readme(problem_number, problem_name, difficulty, topics)

# Функция для создания/обновления README.md
def create_or_update_readme():
    readme_path = 'README.md'
    
    # Проверка на наличие README.md
    if not os.path.exists(readme_path):
        with open(readme_path, 'w', encoding='utf-8') as f:
            # Создаем заголовки и описание
            f.write("# LeetCode Practice Marathon 🏁\n\n")
            f.write("## Overview\n")
            f.write("Welcome to my **LeetCode Practice Marathon** repository! This repository is dedicated to improving my problem-solving and algorithmic skills by solving coding challenges from LeetCode. The goal is to maintain consistency in problem-solving by tackling problems daily and tracking my progress. All solutions are organized by the date they were solved, along with the problem's difficulty and topics covered.\n\n")
            f.write("## Goals\n")
            f.write("- Solve at least **one LeetCode problem every day**.\n")
            f.write("- Enhance my understanding of **data structures** and **algorithms**.\n")
            f.write("- Track my daily progress and reflect on improvements over time.\n")
            f.write("- Build solutions in **C++**, with a focus on writing efficient and clean code.\n\n")
            f.write("## Structure\n")
            f.write("Each problem is saved in a folder named after the date it was solved:\n\n")
            f.write("```\n")
            f.write("|-- /MM.DD.YYYY\n")
            f.write("|    |-- problem_number_problem_name.cpp\n")
            f.write("```\n\n")
            f.write("## Solved Problems\n\n")
            f.write("| Problem Number | Problem Name | Difficulty | Topics | Date Solved |\n")
            f.write("|----------------|--------------|------------|--------|-------------|\n")
    else:
        print("README.md уже существует и будет обновлен.")

# Функция для обновления README.md с новой задачей
def update_readme(problem_number, problem_name, difficulty, topics):
    readme_path = 'README.md'
    
    # Проверка на наличие README.md
    if not os.path.exists(readme_path):
        create_or_update_readme()  # Если README.md нет, создаем его с основными разделами
    
    # Добавляем информацию о новой задаче в конец README
    with open(readme_path, 'a', encoding='utf-8') as f:
        date_solved = datetime.now().strftime('%m.%d.%Y')
        f.write(f"| {problem_number} | {problem_name} | {difficulty} | {topics} | {date_solved} |\n")
    
    print(f"README.md обновлен с задачей {problem_number}: {problem_name}.")

# Функция для выполнения команд Git
def git_push(problem_number):
    try:
        os.system("git add .")
        commit_message = f"Add tsk {problem_number} at {datetime.now().strftime('%m.%d.%Y')}"
        os.system(f'git commit -m "{commit_message}"')
        os.system("git push")
        print("Изменения успешно запушены в репозиторий!")
    except Exception as e:
        print(f"Ошибка при выполнении git команд: {e}")

# Основная функция
def main():
    create_or_update_readme()  # Создаем README, если его еще нет
    
    problem_number = input("Введите номер задачи: ")
    problem_name = input("Введите название задачи: ")
    difficulty = input("Введите сложность задачи (Easy, Medium, Hard): ")
    topics = input("Введите топики задачи (например, Arrays, Dynamic Programming): ")
    
    log_problem(problem_number, problem_name, difficulty, topics)

    # Выполняем команды git для пуша изменений в репозиторий
    git_push(problem_number)

if __name__ == "__main__":
    main()
