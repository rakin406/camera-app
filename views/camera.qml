<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>Camera</class>
 <widget class="QMainWindow" name="Camera">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>1280</width>
    <height>720</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Camera</string>
  </property>
  <widget class="QWidget" name="centralwidget">
  </widget>
  <action name="actionExit">
   <property name="text">
    <string>Exit</string>
   </property>
  </action>
 </widget>
 <resources>
  <include location="camera.qrc"/>
 </resources>
 <connections>
  <connection>
   <sender>recordButton</sender>
   <signal>clicked()</signal>
   <receiver>Camera</receiver>
   <slot>record()</slot>
   <hints>
    <hint type="sourcelabel">
     <x>647</x>
     <y>149</y>
    </hint>
    <hint type="destinationlabel">
     <x>61</x>
     <y>238</y>
    </hint>
   </hints>
  </connection>
  <connection>
   <sender>stopButton</sender>
   <signal>clicked()</signal>
   <receiver>Camera</receiver>
   <slot>stop()</slot>
   <hints>
    <hint type="sourcelabel">
     <x>647</x>
     <y>225</y>
    </hint>
    <hint type="destinationlabel">
     <x>140</x>
     <y>236</y>
    </hint>
   </hints>
  </connection>
  <connection>
   <sender>pauseButton</sender>
   <signal>clicked()</signal>
   <receiver>Camera</receiver>
   <slot>pause()</slot>
   <hints>
    <hint type="sourcelabel">
     <x>647</x>
     <y>187</y>
    </hint>
    <hint type="destinationlabel">
     <x>234</x>
     <y>237</y>
    </hint>
   </hints>
  </connection>
  <connection>
   <sender>actionExit</sender>
   <signal>triggered()</signal>
   <receiver>Camera</receiver>
   <slot>close()</slot>
   <hints>
    <hint type="sourcelabel">
     <x>-1</x>
     <y>-1</y>
    </hint>
    <hint type="destinationlabel">
     <x>154</x>
     <y>130</y>
    </hint>
   </hints>
  </connection>
  <connection>
   <sender>takeImageButton</sender>
   <signal>clicked()</signal>
   <receiver>Camera</receiver>
   <slot>takeImage()</slot>
   <hints>
    <hint type="sourcelabel">
     <x>625</x>
     <y>132</y>
    </hint>
    <hint type="destinationlabel">
     <x>603</x>
     <y>169</y>
    </hint>
   </hints>
  </connection>
 </connections>
 <slots>
  <slot>record()</slot>
  <slot>pause()</slot>
  <slot>stop()</slot>
  <slot>takeImage()</slot>
 </slots>
</ui>
