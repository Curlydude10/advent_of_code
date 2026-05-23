def parse_file(file_name: str) -> str:
    with open(file_name) as file:
        # The input is the first line of the file
        input = file.readline()
    return input


def main():
    input = parse_file("../input.txt")

    floor = 0
    for index, char in enumerate(input):
        if char == "(":
            floor += 1
        elif char == ")":
            floor -= 1

        if floor == -1:
            print(f"The First basement entry is on floor %i", index + 1)

    print(f"The final floor is %i:", floor)


if __name__ == "__main__":
    main()
