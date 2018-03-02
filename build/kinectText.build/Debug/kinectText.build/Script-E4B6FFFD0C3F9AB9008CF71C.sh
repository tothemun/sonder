#!/bin/sh
mkdir -p "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Resources/"
# Copy default icon file into App/Resources
rsync -aved "$ICON_FILE" "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Resources/"
# Copy libfmod and change install directory for fmod to run
rsync -aved ../../../libs/fmodex/lib/osx/libfmodex.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Frameworks/";
install_name_tool -change @executable_path/libfmodex.dylib @executable_path/../Frameworks/libfmodex.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/$PRODUCT_NAME";
# Copy GLUT framework (must remove for AppStore submissions)
rsync -aved ../../../libs/glut/lib/osx/GLUT.framework "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Frameworks/"
cp -R ../../../addons/ofxNI2/libs/OpenNI2/lib/osx/ "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/";
cp -R ../../../addons/ofxNI2/libs/NiTE2/lib/osx/ "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/";


