const template = document.createElement('template');
template.innerHTML = `
    <div>
        <div class="container">
        <div class= "form-check-inline">
            <input class="form-check-input" type="checkbox" name="text-check" value="amplitude-text" id="checkText">
            <label class="form-check-label" for="checkText">Text</label>
            <input type="number" name="text-input" min="1" max="5" value="1" class="form-control" id="text-field">
        </div>
       
        <div class="form-check-inline">
            <input class="form-check-input" type="checkbox" name="slider-check" value="amplitude-slider" id="checkSlider">
            <label class="form-check-label" for="checkSlider">Slider</label>
            <input type="range" name="slider-input"  min="1" max="5" value="1" class="form-control-range" id="slider-field">
            <output id="slider-value"></output>
        </div>
        </div>
        
        
        
        <style>
            #text-field{
                display: none;
                margin-left: 10vh;
                width: 20vh;
                place-content: center;
            }
            #slider-field{
                display: none;
                margin-left: 9vh;
                width: 20vh;
            }
            #slider-value{
                display: none;
            }
            .container{
            margin-left: 20rem;
            }
        </style>
    </div>
`;


class AmplitudeButton extends HTMLElement{
    constructor() {
        super();
        this.attachShadow({mode: 'open'});
        this.shadowRoot.appendChild(template.content.cloneNode(true));
    }

    connectedCallback(){
        this.shadowRoot.querySelector('#slider-value').value = 1;

        this.shadowRoot.querySelector('#checkText').addEventListener('change', () => {
          let checkBox = this.shadowRoot.querySelector('#checkText');
            if (checkBox.checked === true){
                this.shadowRoot.querySelector('#text-field').style.display = "inline-block";
            }
            else {
                this.shadowRoot.querySelector('#text-field').style.display = "none";
            }
        })
        this.shadowRoot.querySelector('#checkSlider').addEventListener('change', () => {
            let checkBox = this.shadowRoot.querySelector('#checkSlider');
            if (checkBox.checked === true){
                this.shadowRoot.querySelector('#slider-field').style.display = "inline-block";
                this.shadowRoot.querySelector('#slider-value').style.display = "inline-block";
            }
            else {
                this.shadowRoot.querySelector('#slider-field').style.display = "none";
                this.shadowRoot.querySelector('#slider-value').style.display = "none";
            }
        })

        this.shadowRoot.querySelector('#text-field').addEventListener('change', () => {
            this.shadowRoot.querySelector('#slider-field').value = this.shadowRoot.querySelector('#text-field').value;
            this.shadowRoot.querySelector('#slider-value').value = this.shadowRoot.querySelector('#text-field').value;
        })
        this.shadowRoot.querySelector('#slider-field').addEventListener('change', () => {
            this.shadowRoot.querySelector('#text-field').value = this.shadowRoot.querySelector('#slider-field').value;
            this.shadowRoot.querySelector('#slider-value').value = this.shadowRoot.querySelector('#slider-field').value;
        })
    }
    getAmplitude(){
        return this.shadowRoot.querySelector('#text-field').value;
    }

}

window.customElements.define('amplitude-button', AmplitudeButton);