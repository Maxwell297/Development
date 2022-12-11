package com.maxwellyao.goodweather.location;

import com.baidu.location.BDLocation;

public interface LocationCallback {
    // 接收定位
    void onReceiveLocation(BDLocation bdLocation);
}
