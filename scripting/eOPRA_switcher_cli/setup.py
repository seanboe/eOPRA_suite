from setuptools import setup, find_packages
with open("README.md", "r", encoding="utf-8") as fh:
    long_description = fh.read()
with open("requirements.txt", "r", encoding="utf-8") as fh:
    requirements = fh.read()
setup(
    name = 'eopra_switcher',
    version = '0.0.4',
    author = 'Sean Boerhout',
    author_email = 'seanboe@mit.edu',
    license = 'MIT',
    description = 'CLI interface to the eOPRA port switcher',
    long_description = long_description,
    long_description_content_type = "text/markdown",
    url = 'https://github.com/seanboe/openServo',
    py_modules = ['main', 'src'],
    packages = find_packages(),
    install_requires = [requirements],
    python_requires='>=3.7',
    classifiers=[
        "Programming Language :: Python :: 3.8",
        "Operating System :: OS Independent",
    ],
    entry_points = '''
        [console_scripts]
        eopra_switcher=main:cli
    '''
)
