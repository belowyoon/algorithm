import os
from urllib import parse

HEADER="""#
# 백준, 프로그래머스 문제 풀이 목록
"""

def main():
    content = ""
    content += HEADER

    categories = {
        "Gold": [],
        "Silver": [],
        "Bronze": [],
        "Other": []
    }

    for root, dirs, files in os.walk("."):
        dirs.sort()
        if root == '.':
            for dir in ('.git', '.github'):
                try:
                    dirs.remove(dir)
                except ValueError:
                    pass
            continue

        category = os.path.basename(root)
        if category in ["images", ".git", ".github"]:
            continue

        directory = os.path.basename(os.path.dirname(root))
        if directory not in ["백준", "프로그래머스"]:
            if category.startswith("Gold"):
                categories["Gold"].append(category)
            elif category.startswith("Silver"):
                categories["Silver"].append(category)
            elif category.startswith("Bronze"):
                categories["Bronze"].append(category)
            else:
                categories["Other"].append(category)

    for medal, medal_categories in categories.items():
        if medal_categories:
            content += "## {} 🏅\n".format(medal)
            content += "| 문제번호 | 링크 |\n"
            content += "| ----- | ----- |\n"
            for category in medal_categories:
                for file in os.listdir(os.path.join(category)):
                    content += "|{}|[링크]({})|\n".format(file, parse.quote(os.path.join(category, file)))
                content += "\n"

    with open("README.md", "w") as fd:
        fd.write(content)

if __name__ == "__main__":
    main()
