package sk.stuba.fei.uim.oop.eshop.user.domain;

import lombok.Data;

@Data
public abstract class Entity {

    protected long id;

    public Entity() {
        this.id = IdGenerator.newId();
    }
}