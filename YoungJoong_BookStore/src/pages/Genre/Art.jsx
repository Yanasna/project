import { ArtData } from "../../database/ArtData";

export default function Art(){
    return(
        <div>
            <p className="title">예술</p>
            {ArtData.map(item=>(<div key={item.id}>{/*ArtData 파일에 있는 내용 map함수로 가져옴*/}
                <div className="book-layout">
                    <img src = {item.bookImg} alt = {item.bookName} className="book-img"/>{/*책의 이미지를 가져온다.*/}
                    <div className="book-info">
                        <p className="book-title">- {item.bookName}</p>{/*책 이름 가져온다.*/}
                        <br />
                        <br />
                        <p>{item.writer}</p>{/*작가, 출판사 정보를 가져온다.*/}
                        <br />
                        <br />
                        <p className="book-price">가격 : {item.price}</p>{/*책의 가격 정보를 가져온다.*/}
                        <br />
                        <br />
                        <div  className="book-explain">
                            <p>{item.explain}</p>{/*책의 줄거리를 가져온다.*/}
                        </div>    
                    </div>               
                </div>
            </div>))}
        </div>
    );
}