package sk.stuba.fei.oop.skuska.domain;

import lombok.Data;

@Data
public abstract class Entity {

    protected long id;

    public Entity() {
        this.id = IdGenerator.newId();
    }

    protected String name;

    public void setName(String name) {
        this.name = name;
    }
}