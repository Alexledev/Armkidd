from setuptools import find_packages
from setuptools import setup

setup(
    name='armkidd_cvprocesser',
    version='0.0.0',
    packages=find_packages(
        include=('armkidd_cvprocesser', 'armkidd_cvprocesser.*')),
)
