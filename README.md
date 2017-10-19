# MySLAM
SLAM

架构出现了点问题，目前是:
一个window有N个照相机，每个照相机有Frame。
而好的架构应该是window有View，每个view有一个照相机，每个照相机有Frame。这么做的好片有
1):每个view来管理照相机
2):可以为view提供不同的渲染设备，比如openglesView,MetalView等等
