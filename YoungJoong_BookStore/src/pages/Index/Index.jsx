import React from "react";
import './Index.css'

export default function Index(){
    return(
        <div>
            <div className="wrapper"> 
                <h1 className="title">책을 읽는다는 것은..</h1>
                <p className="fade">책 읽기는  <span className="bold">지식 습득</span>뿐만 아니라 <span className="bold">개인의 성장</span>을 돕고,</p>
                <p className="fade">다양한 방식으로 <span className="bold">풍요로운 삶</span>을 만들어 줍니다. </p>
                <p className="fade"> 독서를 통해 <span className="bold">지혜와 공감</span>능력을 키우고,  </p>
                <p className="fade"><span className="bold">뇌 기능을 활성화</span>하며,</p>
                <p className="fade"><span className="bold">스트레스와 우울증 해소</span>에도 도움이 됩니다.</p>
                <p className="fade">또한 책은 저렴하고 쉽게 구할 수 있는 <span className="bold">지식의 내구재</span> 역할을 하며,</p>
                <p className="fade"><span className="bold">지속적인 성장</span>을 위한 훌륭한 멘토 역할을 합니다.</p>
                <p className="fade">바쁜시간을 좀 내어서 책을 읽어보는 것이 어떨까요?</p>       
                <img src="/asset/img/index/onebook.jpg" alt="img1" />
                <img src="/asset/img/index/twobook.jpg" alt="img2" />
                <img src="/asset/img/index/threebook.jpg" alt="img3" />
            </div>
        </div>
    );
}