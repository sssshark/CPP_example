set -ex

FILE_DIR=$(cd "$(dirname "$0")";pwd)

if [ ! -d "$FILE_DIR/thirdparty/log4cplus" ]; then
    git clone  --recurse-submodules -b REL_2_0_8 https://github.com/log4cplus/log4cplus.git $FILE_DIR/thirdparty/log4cplus
fi

sed -i '/find_library(LIBNSL nsl)/d' $FILE_DIR/thirdparty/log4cplus/ConfigureChecks.cmake

cd $FILE_DIR/thirdparty/log4cplus

cmake .

make log4cplus -j32

cd -

