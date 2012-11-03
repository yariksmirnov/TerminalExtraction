//
//  Shader.fsh
//  3DTest
//
//  Created by Katekov Anton on 13.02.12.
//  Copyright (c) 2012 SoftFacade. All rights reserved.
//

varying highp vec2 tcoordVarying;

uniform sampler2D colorTexture;
uniform sampler2D colorTexture1;
uniform mediump float alpha;

void main()
{
    //highp vec4 color = texture2D(colorTexture, tcoordVarying);
   // highp vec4 color1 = texture2D(colorTexture1, tcoordVarying);
    
    gl_FragColor = vec4(1.0);//color*alpha + color1*(1.0 - alpha);
}
